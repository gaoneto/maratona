#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 20010

using namespace std;

vector<int> grafo[MAX], grafot[MAX], g[MAX];
int vis[MAX], vist[MAX], ord[MAX], cc, ordem, ent[MAX];

void dfs(int u)
{
    int i, v;
    vis[u]=1;
    for(i=0; i<grafo[u].size(); i++)
    {
        v=grafo[u][i];
        if(!vis[v]) dfs(v);
    }
    ord[ordem++]=u;
}

void dfst(int u)
{
    int i, v;
    vist[u]=cc;
    for(i=0; i<grafot[u].size(); i++)
    {
        v=grafot[u][i];
        if(!vist[v]) dfst(v);
    }
}

int main()
{
    int n, m, i, j, a, b, t, source, sink;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        cc=1;
        ordem=source=sink=0;
        for(i=0; i<n; i++)
        {
            grafo[i].clear();
            grafot[i].clear();
            g[i].clear();
            vis[i]=vist[i]=ent[i]=0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            a--, b--;
            grafo[a].push_back(b);
            grafot[b].push_back(a);
        }
        for(i=0; i<n; i++) if(!vis[i]) dfs(i);
        for(i=n-1; i>=0; i--) if(!vist[ord[i]]) { dfst(ord[i]); cc++; }
        cc--;
        for(i=0; i<n; i++) for(j=0; j<grafo[i].size(); j++)
        {
            a=vist[i]-1;
            b=vist[grafo[i][j]]-1;
            if(a!=b)
            {
                g[a].push_back(b);
                ent[b]=1;
            }
        }
        for(i=0; i<cc && cc!=1; i++)
        {
            if(g[i].empty()) sink++;
            if(!ent[i]) source++;
        }
        printf("%d\n", max(source, sink));
    }
    return 0;
}
