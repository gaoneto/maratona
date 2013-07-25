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

int a[100100], b[100100];

int main()
{
    int i, n, m, k, f=0, p=0, id;
    scanf("%d %d %d", &n, &m, &k);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<m; i++) scanf("%d", &b[i]);
    if(n>m) printf("YES");
    else
    {
        sort(a, a+n);
        sort(b, b+m);
        id=n-1;
        for(i=m-1; i>=0; i--)
        {
            if(b[i]>a[id]) b[i]=a[id];
            else if(b[i]<a[id])
            {
                while(id>=0 && b[i]<a[id]) id--;
                if(id<0) break;
                b[i]=a[id];
            }
        }
        for(i=n-1, id=m-1; i>=0; i--, id--) if(a[i]>b[id])
        {
            printf("YES");
            return 0;
        }
        printf("NO");
    }
    return 0;
}
