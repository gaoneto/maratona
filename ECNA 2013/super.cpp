#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define INF 1000000000

using namespace std;

vector<int> adj[222], ord;
int dp[222][222], vis[222];

void dfs(int u)
{
    int i, v;
    vis[u]=1;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(!vis[v]) dfs(v);
    }
    ord.push_back(u);
}

int main()
{
    int i, j, k, n, m, u, v, t=1;
    char s1[1111], s2[1111];
    while(scanf("%d", &m) && m)
    {
        n=0;
        map<string, int> id;
        vector<pair<string, string> > e, ans;
        ord.clear();
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        for(i=0; i<m; i++)
        {
            scanf("%s %s", s1, s2);
            e.push_back(make_pair(s1, s2));
            if(!id.count(s1)) id[s1]=n++;
            if(!id.count(s2)) id[s2]=n++;
            adj[id[s1]].push_back(id[s2]);
        }
        for(i=0; i<n; i++) if(!vis[i]) dfs(i);
        reverse(ord.begin(), ord.end());
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++) dp[i][j]=-INF;
            dp[i][i]=0;
            for(j=0; j<n; j++)
            {
                u=ord[j];
                for(k=0; k<adj[u].size(); k++)
                {
                    v=adj[u][k];
                    if(dp[i][v]<dp[i][u]+1) dp[i][v]=dp[i][u]+1;
                }
            }
        }
        for(i=0; i<e.size(); i++) if(dp[id[e[i].first]][id[e[i].second]]>1) ans.push_back(e[i]);
        sort(ans.begin(), ans.end());
        printf("Case %d: %d", t++, (int)ans.size());
        for(i=0; i<ans.size(); i++) printf(" %s,%s", ans[i].first.c_str(), ans[i].second.c_str());
        printf("\n");
        for(i=0; i<n; i++) adj[i].clear();
    }
}
