#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

ll comb[222][222], fat[222];
ll memo[222][222][222], memo1[222][222][222];
ll iv[222];

ll light(int n, int m, int p) {
    ll ret=(comb[n][p]*comb[m][p])%mod;
    ret *= fat[p];
    ret %= mod;
    return ret;
}

ll exp(ll a, ll e) {
    if(e == 0) return 1ll;
    if(e%2) return (a*exp(a,e-1)%mod);
    return (exp(a*a%mod,e/2));
}

ll inv(ll a) { return exp(a,mod-2);}

ll heavy(int n, int m, int p) {
    if(n < 0 || m < 0 || p<0) return 0;
    if(p == 1) return (n*m)%mod;
    if(p == 0) return 1;
    if(memo[n][m][p] != -1) return memo[n][m][p];
    ll ret=0;
    ret += ((m-1)*heavy(n-1,m-2,p-2))%mod;
    ret += ((n-1)*heavy(n-2,m-1,p-2))%mod;
    ret += heavy(n-1,m-1,p-1);
    ret *= iv[p];
    ret %= mod;
    ret *= (n*m);
    ret %= mod;
    return memo[n][m][p] = ret;

}

int main() {
    int t, n, m, p, q;
    cin >> t;
    comb[0][0] = 1;
    fat[0] = iv[0] = 1;
    for(int i=1; i<222; i++) fat[i]=(fat[i-1]*i)%mod;
    for(int i=1; i<222; i++) iv[i]=inv(i);
    for(int i=1;i<222;i++) {
        comb[i][0] = 1;
        for(int j=0;j<=i;j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;
        }
    }
    memset(memo,-1,sizeof(memo));
    memset(memo1,-1,sizeof(memo1));
    while(t--) {
        ll ret = 0;
        cin >> n >> m >> p >> q;
        for(int i=0;i<=q;i++) {
            for(int j=0;j<=p;j++) {
                if(i+j) ret = (ret + light(n,m,i)*(heavy(n-i,m-i,j)))%mod;
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}
