#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 50010

using namespace std;

typedef long long ll;

const ll INF=(ll)1e18;
vector<pair<int, ll> > adj[MAX];
vector<ll> d[MAX];
char vis[MAX];
int n;

void dijkstra(int s)
{
    int i, u, v;
    ll w;
    priority_queue<pair<ll, int> > q;
    for(i=0; i<=n+1; i++) vis[i]=0;
    d[s][s]=0;
    q.push(make_pair(-d[s][s], s));
    while(!q.empty())
    {
        u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i].first;
            w=adj[u][i].second;
            if(d[s][v]>d[s][u]+w)
            {
                d[s][v]=d[s][u]+w;
                q.push(make_pair(-d[s][v], v));
            }
        }
    }
}

int main()
{
    int i, m, p[4], a, b, c;
    p[0]=1;
    scanf("%d %d %d %d %d", &n, &m, &p[1], &p[2], &p[3]);
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    sort(p, p+4);
    for(i=0; i<4; i++) d[p[i]]=vector<ll>(n+2, INF);
    for(i=0; i<4; i++) dijkstra(p[i]);
    for(i=1; i<=n; i++) adj[i].push_back(make_pair(n+1, 0));
    ll ans=INF;
    do{
        adj[0].clear();
        for(i=1; i<=n; i++)
        {
            adj[0].push_back(make_pair(i, d[p[0]][i]+d[p[1]][i]));
            adj[i].back().second=d[p[2]][i]+d[p[3]][i];
        }
        d[0]=vector<ll>(n+2, INF);
        dijkstra(0);
        ans=min(ans, d[0][n+1]);
    }while(next_permutation(p, p+3));
    cout << ans << endl;
    return 0;
}
