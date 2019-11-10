#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define all(v) (v).begin(),(v).end()
#define degree(v) adj[v].size()

const int N=4e3+10;
vector<int> g[N];
int nodes, sz[N], nc[N];

map<int, int> tree_nodes;
int cnt;

deque<int> L[N]; //levels
deque<int> sons[N]; //levels
deque<int> subtreeLabels[N];
int pi[N]; int label[N];;
int n; deque<int> adj[N]; int mapping[N];

void dfs(int u, int p) {
	for(int i=0; i<g[u].size(); i++) {
		int v=g[u][i];
		if(v==p) continue;
		dfs(v, u);
		pi[v]=u;
		sz[u]+=1+sz[v];
		if(1+sz[v]>nodes/2) nc[u]=1;
	}
	if(nodes-sz[u]-1>nodes/2) nc[u]=1;
}

void build_tree(int u, int p) {
	if(!tree_nodes.count(u)) tree_nodes[u]=cnt++;
	for(int i=0; i<g[u].size(); i++) {
		int v=g[u][i];
		if(v==p) continue;
		if(!tree_nodes.count(v)) tree_nodes[v]=cnt++;
		int u1=tree_nodes[u], v1=tree_nodes[v];
		adj[u1].push_back(v1);
		adj[v1].push_back(u1);
		build_tree(v, u);
	}
}

bool compare(int a, int b) {
	return (subtreeLabels[a]<subtreeLabels[b]);
}

bool equals(int a, int b) {
	return (subtreeLabels[a]==subtreeLabels[b]);
}

int DFSVisit(int u, int p, int l=0) { // l is levels
	int v, h=0; L[l].push_back(u);
	for(int i=0; i<adj[u].size(); i++) {
		v=adj[u][i];
		if(v==p) continue;
		pi[v]=u; sons[u].push_back(v);
		h=max(h, DFSVisit(v, u, l+1));
	}
	return h+1;
}

void GenerateMapping(int r1, int r2) {
	int u, v; mapping[r1]=r2-n;
	sort(all(sons[r1]), compare); sort(all(sons[r2]), compare);
	for(int i=0; i<sons[r1].size(); i++) {
		u=sons[r1][i];
		v=sons[r2][i];
		GenerateMapping(u,v);
	}
}

bool RootedTreeIsomorphism(int r1, int r2) {
	for(int i=0; i<n; i++) L[i].clear();
	for(int i=0; i<2*n; i++) {
		pi[i]=-1; sons[i].clear();
		subtreeLabels[i].clear();
	}
	int h1=DFSVisit(r1, -1);
	int h2=DFSVisit(r2, -1);
	if(h1!=h2) return false;
	else {
		int h=h1-1;
		for(int i=0; i<L[h].size(); i++) label[L[h][i]]=0;
		for (int i=h-1; i>=0; i--) {
			for(int j=0; j<L[i+1].size(); j++) subtreeLabels[pi[L[i+1][j]]].push_back(label[L[i+1][j]]);
			for(int j=0; j<L[i+1].size(); j++) sort(subtreeLabels[L[i+1][j]].begin(), subtreeLabels[L[i+1][j]].end());
			sort(L[i].begin(), L[i].end(), compare);
			int actualLabel=0;
			label[L[i][0]]=actualLabel;
			for(int j=1; j<L[i].size(); j++) {
				if(!equals(L[i][j], L[i][j-1])) actualLabel++;
				label[L[i][j]]=actualLabel;
			}
		}
		if(equals(r1, r2)) {
			GenerateMapping(r1,r2);
			return true;
		}
		else return false;
	}
}

deque<int> FindCenter(int k) { // k=0 is tree 1, k=1 is tree 2
	deque<int> S, T;
	int r, u, v, cdeg[n]; r=n;
	for(int i=0; i<n; i++) {
		cdeg[i]=degree(i+k*n);
		if(cdeg[i]<=1) {
			S.push_back(i+k*n);
			r--;
		}
	}
	while(r>0) {
		T.clear();
		for(int i=0; i<S.size(); i++) {
			u=S[i];
			for(int j=0; j<adj[u].size(); j++) {
				v=adj[u][j];
				cdeg[v-k*n]--;
				if(cdeg[v-k*n]==1) {
					T.push_back(v);
					r--;
				}
			}
		}
		S=T;
	}
	return S;
}

bool TreeIsomorphism() {
	deque<int> S1=FindCenter(0);
	deque<int> S2=FindCenter(1);
	if(S1.size()!=S2.size()) return false;
	else {
		if(RootedTreeIsomorphism(S1[0], S2[0])) return true;
		else if(S1.size()>1) return RootedTreeIsomorphism(S1[0], S2[1]);
		else return false;
	}
}

int go() {
	int ret=-1;
	for(int i=0; i<nodes; i++) if(!nc[i]) {
		int centroid=i, ok=1, u=g[centroid][0];
		if(u==pi[centroid]) n=nodes-sz[centroid]-1;
		else n=1+sz[u];
		for(int j=1; j<g[centroid].size(); j++) {
			int v=g[centroid][j], sub_size;
			if(v==pi[centroid]) sub_size=nodes-sz[centroid]-1;
			else sub_size=1+sz[v];
			if(n!=sub_size) {
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		cnt=0;
		build_tree(u, centroid);
		for(int j=1; j<g[centroid].size(); j++) {
			u=g[centroid][j];
			cnt=n;
			for(int k=n; k<2*n; k++) adj[k].clear();
			build_tree(u, centroid);
			if(!TreeIsomorphism()) {
				ok=0;
				break;
			}
		}
		if(ok) ret=max(ret, (int)g[centroid].size());
	}
	return ret;
}

int main() {
	int a, b;
	scanf("%d", &nodes);
	for(int i=0; i<nodes; i++) pi[i]=-1;
	for(int i=1; i<nodes; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	printf("%d\n", go());
	return 0;
}
