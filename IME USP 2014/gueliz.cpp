#include <bits/stdc++.h>
#define INF 1000000000
#define MN 100100
#define ME 500500
using namespace std;

int src, snk, E;
int fin[MN], pro[MN], dist[MN];
int next[ME], to[ME], from[ME];
int flow[ME], cap[ME];

void init(int n) {
    int i;
    E=src=0;
    snk=n;
    for(i=0; i<=n; i++) fin[i]=-1;
}

void create_edge(int u, int v, int _cap) {
    from[E]=u, to[E]=v, cap[E]=_cap, flow[E]=0;
    next[E]=fin[u], fin[u]=E++;
}

void add(int u, int v, int _cap) {
    create_edge(u, v, _cap);
    create_edge(v, u, 0);
}

bool bfs() {
    int st, en, i, u, v;
    queue<int> q;
    for(i=0; i<=snk; i++) dist[i]=-1;
    dist[src]=st=en=0;
    q.push(src);
    while(!q.empty()) {
        u=q.front();
        q.pop();
        for(i=fin[u]; i>=0; i=next[i]) {
            v=to[i];
            if(flow[i]<cap[i] && dist[v]==-1) {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=next[e]) {
        v=to[e];
        if(flow[e]<cap[e] && dist[v]==dist[u]+1) {
            df=dfs(v, min(cap[e]-flow[e], fl));
            if(df>0) {
                flow[e]+=df;
                flow[e^1]-=df;
                return df;
            }
        }
    }
    return 0;
}

int dinitz() {
    int i, ret=0, df;
    while(bfs()) {
        for(i=0; i<=snk; i++) pro[i]=fin[i];
        while(1) {
            df=dfs(src, 2*INF);
            if(df) ret+=df;
            else break;
        }
    }
    return ret;
}

vector<int> adj[MN];
int vis[MN], vis1[MN];

void dfs(int u, int p, int c) {
    vis[u]=c;
    vis1[u]=1;
    for(int i=0; i<adj[u].size(); i++) {
        int v=adj[u][i];
        if(v==p) continue;
        dfs(v, u, 1-c);
    }
}

int x[MN], y[MN];

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        memset(vis, 0, sizeof(vis));
        memset(vis1, 0, sizeof(vis1));
        for(int i=1; i<=n; i++) adj[i].clear();
        for(int i=1; i<n; i++) {
            scanf("%d %d", &x[i], &y[i]);
            if(n&1 && (x[i]==1 || y[i]==1)) continue;
            adj[x[i]].push_back(y[i]);
            adj[y[i]].push_back(x[i]);
        }
        for(int i=1; i<=n; i++) if(!vis1[i]) dfs(i, -1, 0);
        init(n+1);
        for(int i=1; i<=n; i++) {
            if(!vis[i]) add(src, i, 1);
            else add(i, snk, 1);
        }
        for(int i=1; i<n; i++) {
            if(n&1 && (x[i]==1 || y[i]==1)) continue;
            if(!vis[x[i]]) add(x[i], y[i], 1);
            else add(y[i], x[i], 1);
        }
        if(n&1) n--;
        if(2*dinitz()==n) {
            vector<pair<int, int> > ans;
            printf("Y\n");
            for(int i=0; i<E; i++) if(flow[i]==1 && from[i]!=src && to[i]!=snk) ans.push_back(make_pair(min(from[i], to[i]), max(from[i], to[i])));
            sort(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
        }
        else printf("N\n");
    }
    return 0;
}
