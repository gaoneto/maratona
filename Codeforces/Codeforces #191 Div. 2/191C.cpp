#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>
#define INF 1000000000
#define EPS 1e-8
#define MOD 1000000007

using namespace std;

typedef long long ll;

char a[100100];

ll fast_exp(ll a, ll n)
{
    ll i=1;
    while(n)
    {
        if(n%2==1) i=(i*a)%MOD;
        n/=2;
        a=(a*a)%MOD;
    }
    return i;
}

int main()
{
    int i;
    ll resp=0, k, size, inv, pot, q;
    cin >> a >> k;
    size=strlen(a);
    pot=(fast_exp(2LL, size)-1+MOD)%MOD;
    inv=fast_exp(pot, MOD-2);
    for(i=0; i<size; i++) if(a[i]=='0' || a[i]=='5')
    {
        pot=fast_exp(2LL, (ll)i);
        q=(fast_exp(2LL, k*size)-1+MOD)%MOD;
        resp=(resp+(((pot*q)%MOD)*inv)%MOD)%MOD;
    }
    cout << resp;
    return 0;
}
