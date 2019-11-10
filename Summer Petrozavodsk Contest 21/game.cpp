#include <bits/stdc++.h>
using namespace std;

//Problema igual com explanation: CERC 2011 - Racing Car Trail
//Partindo de um vértice que ñ tem match -> lose
//Para um dado vértice, encontra-se maximum matching sem ele:
//Se houver caminho aumentante -> win
//Senão -> lose

const int N=1e3+10;
int match[N], vis[N], del;
vector<int> adj[N];

int dfs(int u) {
	if(vis[u]) return 0;
	vis[u]=1;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(v==del) continue;
		if(match[v]==-1 || dfs(match[v])) {
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

//Finds matching in O(V*E)
void kuhn(int n) {
	memset(match, -1, sizeof(match));
	for(int i=0; i<n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i);
	}
}

int main() {
	int n1, n2, m;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d %d %d", &n1, &n2, &m);
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(n1+b);
		adj[n1+b].push_back(a);
	}
	del=-1;
	kuhn(n1);
	for(int i=0; i<n1+n2; i++) {
		if(i==n1) printf("\n");
		if(match[i]==-1) printf("P");
		else {
			int v=match[i];
			match[i]=match[v]=-1;
			del=i;
			memset(vis, 0, sizeof(vis));
			if(dfs(v)) printf("P");
			else {
				printf("N");
				match[i]=v;
				match[v]=i;
			}
		}
	}
	printf("\n");
	return 0;
}
