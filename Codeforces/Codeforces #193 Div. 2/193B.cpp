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

using namespace std;

typedef long long ll;

ll x[200100], suml[200100], sumr[200100], dpl[200100], dpr[200100], resp=0LL;
int pl[200100], pr[200100];

int main()
{
    int i, n, k, l, r;
    cin >> n >> k;
    l=1, r=n-k+1;
    for(i=1; i<=n; i++)
    {
        cin >> x[i];
        pl[i]=1;
        pr[i]=n-k+1;
    }
    for(i=1; i<=n; i++)
    {
        suml[i]=suml[i-1]+x[i];
        if(i>=k)
        {
            if(dpl[i-1]>suml[i]-suml[i-k])
            {
                dpl[i]=dpl[i-1];
                pl[i]=pl[i-1];
            }
            else
            {
                dpl[i]=suml[i]-suml[i-k];
                pl[i]=i-k+1;
            }
        }
    }
    for(i=n; i>=1; i--)
    {
        sumr[i]=sumr[i+1]+x[i];
        if(i<=n-k+1)
        {
            if(dpr[i+1]>sumr[i]-sumr[i+k])
            {
                dpr[i]=dpr[i+1];
                pr[i]=pr[i+1];
            }
            else
            {
                dpr[i]=sumr[i]-sumr[i+k];
                pr[i]=i;
            }
        }
    }
    for(i=0; i<=n; i++) if(dpl[i]+dpr[i+1]>resp)
    {
        resp=dpl[i]+dpr[i+1];
        l=pl[i];
        r=pr[i+1];
    }
    cout << l << " " << r;
    return 0;
}
