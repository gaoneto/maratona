#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10, SN=4e2;
char a[SN];
int prime[SN], nprimes=1, p[SN], e[SN], k, ndivisors, divisor[SN], f[N];

void sieve() {
    int i, j;
    for(i=2; i<SN; i+=2) a[i]=1;
    prime[0]=2;
    for(i=3; i<SN; i+=2) {
        if(a[i]) continue;
        prime[nprimes++]=i;
        for(j=2*i; j<SN; j+=i) a[j]=1;
    }
}

void factor(int n) {
    int j;
    k=0;
    for(j=0; prime[j]*prime[j]<=n; ++j) if(n%prime[j]==0) {
        p[k]=prime[j]; 
        e[k]=0;
        while(n%prime[j]==0) { 
            n/=prime[j]; 
            e[k]++; 
        }
        ++k;
    }
    if(n!=1) { 
        p[k]=n; 
        e[k]=1; 
        ++k;
    }
}

void divisors() {
    int r, i, j, a;
    ndivisors=1; 
    divisor[0]=1; 
	f[1]=1;
    for(i=0; i<k; i++) {
        r=ndivisors;
        for(j=0; j<e[i]; j++) for(a=0; a<r; a++) {
			divisor[ndivisors]=p[i]*divisor[a+j*r];
			f[divisor[ndivisors++]]=1;
		}
    }
}

vector<int> adj[N];
int vis[N], c[N], mdc, again[N], valid[N];

void dfs(int u, int val) {
	vis[u]=1;
	valid[mdc]=1;
	if(mdc==val) return;
	for(int i=0; i<adj[u].size(); i++) {
		int v=adj[u][i];
		if(!vis[v]) {
			mdc=__gcd(mdc, c[v]);
			valid[mdc]=1;
			if(mdc==val) return;
			dfs(v, val);
		}
	}
}

int main() {
    int n, m, a, b;
    sieve();
    while(scanf("%d %d", &n, &m)!=EOF) {
		for(int i=0; i<N; i++) f[i]=again[i]=valid[i]=0;
		for(int i=0; i<n; i++) {
			scanf("%d", &c[i]);
			if(!again[c[i]]) {
				factor(c[i]);
				again[c[i]]=valid[c[i]]=1;
				divisors();
			}
			adj[i].clear();
		}
		for(int i=0; i<m; i++) {
			scanf("%d %d", &a, &b);
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=1; i<N; i++) if(f[i] && !valid[i]) {
			for(int j=0; j<n; j++) {
				if(c[j]%i!=0) vis[j]=1;
				else vis[j]=0;
			}
			for(int j=0; j<n; j++) if(!vis[j]) {
				mdc=c[j];
				dfs(j, i);
				if(mdc==i) break;
			}
		}
		int ans=0;
		for(int i=0; i<N; i++) if(valid[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
