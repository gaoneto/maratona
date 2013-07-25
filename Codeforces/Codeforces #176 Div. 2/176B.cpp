#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

ll sum(ll a, ll b)
{
    ll n=b-a+1;
    return (a+b)*n/2-(n-1);
}

int main()
{
    int i;
    ll n, k, lo, mid, hi;
    cin >> n >> k;
    if(n>(k*(k-1)/2+1)) cout << "-1";
    else if(n==1) cout << "0";
    else if(n<=k) cout << "1";
    else
    {
        lo=2;
        hi=k;
        mid=(lo+hi)/2;
        while(lo<hi)
        {
            if(sum(mid, k)>=n) lo=mid+1;
            else hi=mid;
            mid=(lo+hi)/2;
        }
        cout << k-mid+2;
    }
    return 0;
}
