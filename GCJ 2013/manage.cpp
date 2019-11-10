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

int e, r, n, v[20], maximo;

void dfs(int u, int left, int sum)
{
    int i;
    if(u==n-1)
    {
        if(sum+left*v[u]>maximo) maximo=sum+left*v[u];
        return;
    }
    for(i=0; i<=left; i++) dfs(u+1, min(e, left-i+r), sum+i*v[u]);
}

int main()
{
    int i, t, aux=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &e, &r, &n);
        for(i=0; i<n; i++) scanf("%d", &v[i]);
        maximo=0;
        dfs(0, e, 0);
        printf("Case #%d: %d\n", aux++, maximo);
    }
    return 0;
}
