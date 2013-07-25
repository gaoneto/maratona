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

vector<int> grafo[1010], group;
int vis[1010], possivel[2000], ent[1010], flag=0;

int dfs(int u)
{
    int i, v;
    vis[u]=1;
    for(i=0; i<grafo[u].size(); i++)
    {
        v=grafo[u][i];
        if(!vis[v]) return 1+dfs(v);
        else
        {
            flag=1;
            return 0;
        }
    }
    return 0;
}

int main()
{
    int i, n, x, a[1010], ret, maximo, j;
    scanf("%d %d", &n, &x);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i])
        {
            grafo[i].push_back(a[i]);
            ent[a[i]]=1;
        }
    }
    ret=dfs(x);
    group.push_back(ret+1);
    for(i=1; i<=n; i++) if(!vis[i] && !ent[i])
    {
        ret=dfs(i);
        if(!flag) group.push_back(ret+1);
        else flag=0;
    }
    possivel[0]=1;
    for(i=1, maximo=0; i<group.size(); i++)
    {
        for(j=maximo; j>=0; j--) if(possivel[j]) possivel[j+group[i]]=1;
        maximo+=group[i];
    }
    for(i=0; i<=maximo; i++) if(possivel[i]) printf("%d\n", i+group[0]);
    return 0;
}
