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

vector<int> g[50], group[50];
int vis[50], cont;

void dfs(int u)
{
    int i, v;
    vis[u]=1;
    group[cont].push_back(u);
    for(i=0; i<g[u].size(); i++)
    {
        v=g[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    int i, n, m, a, b, f=0, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=0; i<n; i++) if(g[i].size()>2) f=1;
    if(f) printf("-1");
    else
    {
        cont=0;
        for(i=0; i<n; i++) if(!vis[i])
        {
            dfs(i);
            if(group[cont].size()>3)
            {
                f=1;
                break;
            }
            cont++;
        }
        if(f) printf("-1");
        else
        {
            for(i=0; i<n; i++) vis[i]=0;
            for(i=0; i<cont; i++) if(group[i].size()==2) for(j=0; j<n; j++) if(!vis[j] && g[j].empty())
            {
                group[i].push_back(j);
                vis[j]=1;
                break;
            }
            for(i=0; i<cont; i++) if(group[i].size()==1 && !vis[group[i][0]])
            {
                vis[group[i][0]]=1;
                for(j=0; j<n; j++) if(!vis[j] && g[j].empty() && j!=group[i][0])
                {
                    group[i].push_back(j);
                    vis[j]=1;
                    if(group[i].size()==3) break;
                }
            }
            for(i=0; i<cont; i++) if(group[i].size()==1 && !vis[group[i][0]]) f=1;
            if(f) printf("-1");
            else
            {
                for(i=0; i<cont; i++) if(group[i].size()==2) f=1;
                if(f) printf("-1");
                else
                {
                    for(i=0; i<cont; i++) if(group[i].size()==3) printf("%d %d %d\n", group[i][0]+1, group[i][1]+1, group[i][2]+1);
                }
            }
        }
    }
    return 0;
}
