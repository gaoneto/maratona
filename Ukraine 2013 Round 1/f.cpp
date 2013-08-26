#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define M 1000000007

ll mod(ll a) { return (a%M + M)%M; }

ll exp(ll a, ll e) {
    if(e==0) return 1;
    if(e%2==0) return exp(mod(a*a), e/2);
    return mod(a*exp(a, e-1));
}

ll inv(ll a) { return exp(a, M-2); }

ll mdc(ll a, ll b) { return !b?a:mdc(b, a%b); }
ll mmc(ll a, ll b) { return a*(b/mdc(a, b)); }

ll sum(ll a, ll n) { 
    ll m = n/a;
    if(n%a == 0) m--;
    m = mod(m);
    return mod(mod(mod(a*m) * (m+1)) * inv(2));
}

int main() {
    ll n, a, b, s1, s2;
    cin>>n>>a>>b;
    s1=mod(sum(a, n) + sum(b, n));
    ll gcd=mdc(a, b);
    if((double)b/gcd > (double)n/a) s2=0;
    else s2=sum(mmc(a, b), n);
    cout << mod(s1 - s2) << endl;
    return 0;
}
