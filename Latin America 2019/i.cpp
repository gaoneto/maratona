#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

const int N=2e3+10;
vector<int> adj[N], ord;
int vis[N], dp[N];

void dfs(int u) {
	vis[u]=1;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(vis[v]) continue;
		dfs(v);
	}
	ord.push_back(u);
}

int main() {
	int n, l, k, m, tot=0, ans=0;
	scanf("%d %d", &n, &l);
	for(int i=0; i<l; i++) {
		scanf("%d", &k);
		for(int j=0; j<k; j++) {
			scanf("%d", &m);
			m--;
			adj[i].push_back(m);
		}
	}
	dfs(0);
	dp[0]=1;
	for(int i=(int)ord.size()-1; i>=0; i--) {
		int u=ord[i];
		for(int j=0; j<adj[u].size(); j++) {
			int v=adj[u][j];
			dp[v]=(dp[v]+dp[u])%MOD;
		}
	}
	for(int i=0; i<ord.size(); i++) if(ord[i]>=l) {
		ans++;
		tot=(tot+dp[ord[i]])%MOD;
	}
	printf("%d %d\n", tot, ans);
	return 0;
}
