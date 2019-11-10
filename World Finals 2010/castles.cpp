#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a[111], m[111], dp[111], s[111];
vector<int> adj[111];

bool cmp(int x, int y) { return (dp[x]-s[x])>(dp[y]-s[y]); }

void dfs(int u, int p)
{
    int i, v, tot, ans, sum;
    vector<int> ord;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(v==p) continue;
        ord.push_back(v);
        dfs(v, u);
    }
    if(ord.empty()) return;
    sort(ord.begin(), ord.end(), cmp);
    ans=sum=tot=0;
    for(i=0; i<ord.size(); i++)
    {
        v=ord[i];
        sum+=s[v];
        if(tot<dp[v]) ans+=(dp[v]-tot);
        tot=ans-sum;
    }
    ans=max(ans+s[u],dp[u]);
    s[u]=sum+s[u];
    dp[u]=ans;
}

int main()
{
    int i, j, n, u, v, g, t=1;
    while(scanf("%d", &n) && n)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d %d %d", &a[i], &m[i], &g);
            m[i]+=g;
            a[i]=max(a[i], m[i]);
            adj[i].clear();
        }
        for(i=1; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=1<<30;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++) dp[j]=a[j], s[j]=m[j];
            dfs(i, -1);
            ans=min(ans, dp[i]);
        }
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}

