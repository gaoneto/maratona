#include <cstdio>
#include <vector>

using namespace std;

vector<int> grafo[1111], grafot[1111];
int vis[1111], vist[1111], ord[1111], cc, ordem, ent[1111], c0;

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
    if(!u) c0=cc-1;
    for(i=0; i<grafot[u].size(); i++)
    {
        v=grafot[u][i];
        if(!vist[v]) dfst(v);
    }
}

int main()
{
    int n, m, i, j, a, b, ans;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        cc=1;
        ordem=ans=0;
        for(i=0; i<=n; i++)
        {
            grafo[i].clear();
            grafot[i].clear();
            vis[i]=vist[i]=ent[i]=0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            grafo[a].push_back(b);
            grafot[b].push_back(a);
        }
        for(i=0; i<=n; i++) if(!vis[i]) dfs(i);
        for(i=n; i>=0; i--) if(!vist[ord[i]]) { dfst(ord[i]); cc++; }
        for(i=0; i<=n; i++) for(j=0; j<grafo[i].size(); j++)
        {
            a=vist[i]-1;
            b=vist[grafo[i][j]]-1;
            if(a!=b) ent[b]++;
        }
        for(i=0; i<cc-1; i++) if(i!=c0 && !ent[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
