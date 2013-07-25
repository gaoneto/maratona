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

ll a[100100], sum[100100];
int p[100100];

int main()
{
    int i, n, m, t, v, x, y, q;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) cin >> a[i];
    sum[0]=0LL;
    for(i=1; i<=m; i++)
    {
        scanf("%d", &t);
        sum[i]=sum[i-1];
        if(t==1)
        {
            scanf("%d %d", &v, &x);
            a[v]=x;
            p[v]=i;
        }
        else if(t==2)
        {
            scanf("%d", &y);
            sum[i]+=y;
        }
        else
        {
            scanf("%d", &q);
            cout << a[q]+sum[i]-sum[p[q]] << endl;
        }
    }
    return 0;
}
