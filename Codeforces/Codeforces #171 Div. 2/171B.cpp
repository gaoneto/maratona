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

ll a[100100];

int main()
{
    int i, n, lo=0, hi=0, maximo=0;
    ll t, sum=0;
    cin >> n >> t;
    for(i=0; i<n; i++) cin >> a[i];
    while(hi<n)
    {
        sum+=a[hi];
        if(sum<=t && hi-lo+1>maximo) maximo=hi-lo+1;
        if(sum>t)
        {
            sum-=a[lo++];
            if(sum<=t && hi-lo+1>maximo) maximo=hi-lo+1;
        }
        hi++;
    }
    printf("%d", maximo);
    return 0;
}
