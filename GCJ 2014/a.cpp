#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll a) { return a>0 ? a : -a; }

int go(ll p, ll q)
{
    ll mdc=__gcd(mod(2*p-q), q);
    ll x=(2*p-q)/mdc, y=q/mdc;
    if(2*p>=q && !(y&(y-1))) return 1;
    return 1+go(2*p/mdc, q/mdc);
}

int main()
{
    int t=1, T;
    ll p, q;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld/%lld", &p, &q);
        printf("Case #%d: ", t++);
        ll mdc=__gcd(p, q);
        p/=mdc, q/=mdc;
        if(q&(q-1)) printf("impossible\n");
        else printf("%d\n", go(p, q));
    }
    return 0;
}
