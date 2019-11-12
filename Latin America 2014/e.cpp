#include <bits/stdc++.h>
using namespace std;

const int C=1e5+10, N=1e4+10, SN=350;
char a[SN];
int prime[SN], nprimes=1, p[SN], e[SN], k, ndivisors, divisor[SN], d[C];

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
    ndivisors=1; 
    divisor[0]=1; 
	d[1]=1;
    for(int i=0; i<k; i++) {
        int r=ndivisors;
        for(int j=0; j<e[i]; j++) for(int a=0; a<r; a++) {
			divisor[ndivisors]=p[i]*divisor[a+j*r];
			d[divisor[ndivisors]]=1;
			ndivisors++;
		}
    }
}

vector<int> adj[N];
int vis[N], valid[C], c[N], mdc, cnt=1;

int bfs(int u, int goal) {
	queue<int> q;
	q.push(u);
	vis[u]=cnt;
	while(!q.empty()) {
		u=q.front();
		q.pop();
		for(int i=0; i<adj[u].size(); i++) {
			int v=adj[u][i];
			if(vis[v]<cnt) {
				vis[v]=cnt;
				q.push(v);
				mdc=__gcd(mdc, c[v]);
				valid[mdc]=1;
				if(mdc==goal) return 1;
			}
		}
	}
	return 0;
}

int main() {
    int n, m, a, b, _max=0;
    sieve();
    scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", &c[i]);
		factor(c[i]);
		divisors();
		valid[c[i]]=1;
		_max=max(_max, c[i]);
	}
	for(int i=0; i<m; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		valid[__gcd(c[a], c[b])]=1;
	}
	for(int i=_max; i>=1; i--) if(d[i] && !valid[i]) {
		for(int j=0; j<n; j++) if(c[j]%i!=0) vis[j]=cnt;
		for(int j=0; j<n; j++) if(vis[j]<cnt && c[j]%i==0) {
			mdc=c[j];
			int ret=bfs(j, i);
			if(ret) valid[i]=1;
		}
		cnt++;
	}
	int ans=0;
	for(int i=0; i<=_max; i++) if(valid[i]==1) ans++;
	printf("%d\n", ans);
	return 0;
}
