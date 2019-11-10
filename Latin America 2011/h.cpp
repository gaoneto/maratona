#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 10010

using namespace std;

vector<int> grafo[MAX], ponte[MAX];
int vis[MAX], t, men[MAX], ret, n, visp[MAX], cc;
queue<int> Q;

void bfs(int s)
{
    int u, v, i;
    visp[s]=cc;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0; i<ponte[u].size(); i++)
        {
            v=ponte[u][i];
            if(!visp[v])
            {
                visp[v]=cc;
                Q.push(v);
            }
        }
    }
}

void dfs(int v, int p, int ind)
{
    int i, w;
    if(vis[v]) return;
    vis[v]=++t;
    men[v]=vis[v];
    for(i=0; i<grafo[v].size(); i++)
    {
        w=grafo[v][i];
        if(w==p) continue;
        if(vis[w])
        {
            if(men[v]>vis[w])
                men[v]=vis[w];
        }
        else
        {
            dfs(w, v, i);
            if(men[v]>men[w])
                men[v]=men[w];
        }
    }
    if(p>=0 && men[v]>=vis[v])
    {
        ret++;
        ponte[p].push_back(grafo[p][ind]);
        ponte[grafo[p][ind]].push_back(p);
    }
}

void bridge()
{
    int i;
    for(i=0; i<n; i++) vis[i]=0;
    t=ret=0;
    for(i=0; i<n; i++)
        if(!vis[i])
            dfs(i, -1, 0);
    //return ret;
}

int main()
{
    int i, j, q, c, a, b;
    while(scanf("%d %d %d", &n, &c, &q) && (n || c || q))
    {
        for(i=0; i<n; i++)
        {
            grafo[i].clear();
            ponte[i].clear();
            visp[i]=0;
        }
        for(i=0; i<c; i++)
        {
            scanf("%d %d", &a, &b);
            a--, b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        bridge();
        cc=1;
        for(i=0; i<n; i++)
            if(!visp[i])
            {
                bfs(i);
                cc++;
            }
        for(i=0; i<q; i++)
        {
            scanf("%d %d", &a, &b);
            a--, b--;
            if(visp[a]==visp[b]) printf("Y\n");
            else printf("N\n");
        }
        printf("-\n");
    }
    return 0;
}
