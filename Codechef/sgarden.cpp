#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int a[111111], vis[111111];

ll exp(ll a, ll e) {
	if(!e) return 1;
	if(e&1) return ((a%MOD)*(exp(a, e-1)%MOD))%MOD;
	return (exp((a*a)%MOD, e/2))%MOD;
}

ll inv(ll a) { return (exp(a, MOD-2))%MOD; }

ll gcd(ll a, ll b) { return (!b) ? a : gcd(b, a%b); }

ll lcm(ll a, ll b) { return ((((a%MOD)*inv(gcd(a, b)))%MOD)*b)%MOD; }

int main() {
    int n, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		ll ans=1;
		for(int i=1; i<=n; i++) if(!vis[i]) {
			int cur=i, cnt=0;
			while(1) {
				vis[cur]=1;
				cur=a[cur];
				cnt++;
				if(cur==i) break;
			}
			ans=lcm(ans, cnt);
		}
		printf("%lld\n", ans%MOD);
	}
    return 0;
}
