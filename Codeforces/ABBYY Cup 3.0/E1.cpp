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

ll a[200100], f[200100], v, MOD=1000000000LL, sum;

int main()
{
    int i, n, m, x, l, r, j, t;
    cin >> n >> m;
    f[0]=f[1]=1;
    for(i=2; i<200100; i++) f[i]=(f[i-1]+f[i-2])%MOD;
    for(i=1; i<=n; i++) cin >> a[i];
    for(i=0; i<m; i++)
    {
        scanf("%d", &t);
        if(t==1)
        {
            cin >> x >> v;
            a[x]=v;
        }
        else if(t==2)
        {
            cin >> l >> r;
            sum=0LL;
            for(j=l; j<=r; j++) sum=(sum+f[j-l]*a[j])%MOD;
            cout << sum << endl;
        }
    }
    return 0;
}
