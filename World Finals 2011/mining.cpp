#include <bits/stdc++.h>
#define MAXN 111111
using namespace std;

typedef long long ll;

int n, t, ret, one;
int mrk[MAXN], men[MAXN], art[MAXN];
vector<int> adj[MAXN], g[MAXN];

void dfs(int v, int p)
{
    int i, w, plus;
    if(mrk[v]) return;
    mrk[v]=++t;
    men[v]=mrk[v];
    plus=0;
    for(i=0; i<adj[v].size(); i++)
    {    
        w=adj[v][i];
        if(w==p) continue;
        if(mrk[w])
        {
            if(men[v]>mrk[w]) men[v]=mrk[w];
        }
        else
        {
            if(p==0) one++;
            dfs(w, v);
            if(men[v]>men[w]) men[v]=men[w];
            if((men[w]>=mrk[v]) && (p>0))
            {
                plus=1;
                art[v]=1;
            }
        } 
    }
    ret+=plus;
}

int articulation()
{    
    int i;   
    if(n==1) return 0;
    for(i=1; i<=n; i++) mrk[i]=art[i]=0;
    ret=t=0;
    for(i=1; i<=n; i++) if(!mrk[i])
    {
        one=0;
        dfs(i, 0); 
        if(one>1)
        {
            art[i]=1;
            ret++;
        }
    }
    return ret; 
}

int a[MAXN], b[MAXN], tam[MAXN], cc, vis[MAXN], cnt[MAXN], used[MAXN];

void dfs1(int u)
{
    int i, v;
    vis[u]=cc;
    tam[cc]++;
    for(i=0; i<g[u].size(); i++)
    {
        v=g[u][i];
        if(!vis[v]) dfs1(v);
    }
}

int main()
{
    int m, i, T=1, ok;
    while(scanf("%d", &m) && m)
    {
        n=0;
        cc=ok=1;
        ll ans=1;
        memset(tam, 0, sizeof(tam));
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        memset(used, 0, sizeof(used));
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a[i], &b[i]);
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
            n=max(n, max(a[i], b[i]));
        }
        articulation();
        for(i=0; i<m; i++) if(!art[a[i]] && !art[b[i]])
        {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
        for(i=1; i<=n; i++) if(art[i]) ok=0;
        for(i=1; i<=n; i++) if(!art[i] && !vis[i])
        {
            dfs1(i);
            cc++;
        }
        for(i=1; i<=n; i++) if(art[i])
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                int u=adj[i][j];
                if(used[vis[u]]!=i) cnt[vis[u]]++, used[vis[u]]=i;
            }
        }
        int resp=0;
        for(i=1; i<cc; i++) if(cnt[i]==1) resp++, ans*=tam[i];
        printf("Case %d: ", T++);
        if(ok) printf("2 %lld\n", 1ll*n*(n-1)/2);
        else printf("%d %lld\n", resp, ans);
        for(i=1; i<=n; i++) adj[i].clear(), g[i].clear();
    }
    return 0;
}
