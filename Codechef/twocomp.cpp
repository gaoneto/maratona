#include <bits/stdc++.h>
#define INF 1000000000
#define MN 1444
#define ME 555555
#define MAX 100010
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
    assert(E<ME);
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

int pi[MAX], level[MAX], P[MAX][20], n;
vector<int> adj[MAX];

void process() {
    int i, j;
    for(i=0; i<n; i++) for(j=0; (1<<j)<n; j++) P[i][j]=-1;
    for(i=0; i<n; i++) P[i][0]=pi[i];
    for(j=1; (1<<j)<n; j++) for(i=0; i<n; i++) if(P[i][j-1]!=-1) P[i][j]=P[P[i][j-1]][j-1];
}

int query(int p, int q) {
    int log, i;
    if(level[p]<level[q]) swap(p, q);
    for(log=1; (1<<log)<=level[p]; log++);
    log--;
    for(i=log; i>=0; i--) if(level[p]-(1<<i)>=level[q]) p=P[p][i];
    if(p==q) return p;
    for(i=log; i>=0; i--) if(P[p][i]!=-1 && P[p][i]!=P[q][i]) {
        p=P[p][i];
        q=P[q][i];
    }
    return pi[p];
}

void go(int u, int p) {
    int i, v;
    for(i=0; i<adj[u].size(); i++) {
        v=adj[u][i];
        if(v==p) continue;
        level[v]=level[u]+1;
        pi[v]=u;
        go(v, u);
    }
}

//verify if node p is in path from s and t, s = lca(s, t)
int in_path(int p, int s, int t) {
    if(query(p, s)==s && query(p, t)==p) return 1;
    return 0;
}

int solve(int s1, int t1, int s2, int t2, int lca) {
    int n1=query(s1, t1), n2=query(s2, t2);
    assert(level[s1]<=level[t1] && level[s2]<=level[t2]);
    if(in_path(lca, n1, s1) && in_path(lca, n1, t1) && in_path(lca, n2, s2) && in_path(lca, n2, t2)) return 1;
    return 0;
}

int intersect(int s1, int t1, int s2, int t2) {
    if(level[s1]>level[t1]) swap(s1, t1);
    if(level[s2]>level[t2]) swap(s2, t2);
    if(solve(s1, t1, s2, t2, query(s1, t1))) return 1;
    if(solve(s1, t1, s2, t2, query(s1, t2))) return 1;
    if(solve(s1, t1, s2, t2, query(s2, t1))) return 1;
    if(solve(s1, t1, s2, t2, query(s2, t2))) return 1;
    if(solve(s1, t1, s2, t2, query(s1, s2))) return 1;
    if(solve(s1, t1, s2, t2, query(t1, t2))) return 1;
    return 0;
}

int main() {
    int m1, m2, a, b, c, bx[777], by[777], weight=0;
    scanf("%d %d %d", &n, &m1, &m2);
    init(m1+m2+1);
    pi[0]=-1;
    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    go(0, -1);
    process();
    for(int i=0; i<m1; i++) {
        scanf("%d %d %d", &bx[i], &by[i], &c);
        bx[i]--, by[i]--;
        weight+=c;
        add(src, i+1, c);
    }
    for(int i=0; i<m2; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        weight+=c;
        add(i+1+m1, snk, c);
        for(int j=0; j<m1; j++) if(intersect(bx[j], by[j], a, b)) add(j+1, i+1+m1, INF);
    }
    printf("%d\n", weight-dinitz());
    return 0;
}
