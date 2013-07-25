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

int main()
{
    int i, n, m, a[111], x, y;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &x, &y);
        x--;
        if(x) a[x-1]+=y-1;
        a[x+1]+=a[x]-y;
        a[x]=0;
    }
    for(i=0; i<n; i++) printf("%d\n", a[i]);
    return 0;
}
