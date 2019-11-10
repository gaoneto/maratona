#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int N=1e5+10;
vector<int> adj[N];
ll dp[N][3];

ll exp(ll a, ll e) {
	if(!e) return 1;
	if(e&1) return ((a%MOD)*(exp(a, e-1)%MOD))%MOD;
	return (exp((a*a)%MOD, e/2))%MOD;
}

ll inv(ll a) { return (exp(a, MOD-2))%MOD; }

void dfs(int u, int p) {
	ll prod=1, prod2=1, sum=0, sum2=0, sum22=0, cnt=0, pos=-1;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(v==p) continue;
		dfs(v, u);
		if(!dp[v][2]) {
			cnt++;
			pos=v;
		}
		else prod2=(prod2*dp[v][2])%MOD;
		prod=(prod*dp[v][2])%MOD;
		sum=(((sum+dp[v][0])%MOD)+dp[v][1])%MOD;
		sum2=(((sum2+(dp[v][0]*dp[v][0])%MOD)%MOD)+(dp[v][1]*dp[v][1])%MOD)%MOD;
		sum22=(sum22+(dp[v][0]*dp[v][1])%MOD)%MOD;
	}
	sum22=(sum22*2)%MOD;
	dp[u][0]=prod;
	dp[u][2]=(((((sum*sum)%MOD)-sum2-sum22+MOD*2)%MOD)*inv(2))%MOD;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(v==p) continue;
		if(!cnt) dp[u][1]=(dp[u][1]+(((((dp[v][0]+dp[v][1])%MOD)*inv(dp[v][2]))%MOD)*prod)%MOD)%MOD;
		else if(cnt==1 && pos==v) dp[u][1]=(dp[u][1]+(((dp[v][0]+dp[v][1])%MOD)*prod2)%MOD)%MOD;
	}
	printf("%d %lld %lld %lld\n", u+1, dp[u][0], dp[u][1], dp[u][2]);
}

int main() {
	int n, u, v;
	scanf("%d", &n);
	for(int i=1; i<n; i++) {
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	return 0;
}
