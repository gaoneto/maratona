#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
 
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
 
#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
 
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAXN = 222;
const int MAXE = 22222;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], nxt[MAXE], to[MAXE], from[MAXE];
 
inline void init(int _src, int _snk, int nodes) {
    SET(fin);
    nNode = nodes, nEdge = 0;
    src = _src, snk = _snk;
}
 
inline void addEdge(int u, int v, int _cap, int _cost) {
    from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
    nxt[nEdge] = fin[u], fin[u] = nEdge++;
    from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
    nxt[nEdge] = fin[v], fin[v] = nEdge++;
}
 
bool bellman() {
    int iter, u, v, i;
    bool flag = true;
    MEM(dist, 0x7f);
    SET(pre);
    dist[src] = 0;
    for(iter = 1; iter < nNode && flag; iter++) {
        flag = false;
        for(u = 0; u < nNode; u++) {
            for(i = fin[u]; i >= 0; i = nxt[i]) {
                v = to[i];
                if(cap[i] && dist[v] > dist[u] + cost[i]) {
                    dist[v] = dist[u] + cost[i];
                    pre[v] = i;
                    flag = true;
                }
            }
        }
    }
    return (dist[snk] < INF);
}
 
int mcmf(int &fcost) {
    int netflow, bot, u;
    netflow = fcost = 0;
    while(bellman()) {
        bot = INF;
        for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot = min(bot, cap[u]);
        for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
            cap[u] -= bot;
            cap[u^1] += bot;
            fcost += bot * cost[u];
        }
        netflow += bot;
    }
    return netflow;
}

int main() {
    int n, r, i, j, xr[222], yr[222], xc[222], yc[222], cost;
    while(scanf("%d %d", &r, &n)!=EOF) {
        for(i=1; i<=r; i++) scanf("%d %d", &xr[i], &yr[i]);
        for(i=1; i<=n; i++) scanf("%d %d", &xc[i], &yc[i]);
        init(0, n+r+1, n+r+2);
        for(i=1; i<=r; i++) addEdge(0, i, 1, 0);
        for(i=1; i<=n; i++) addEdge(r+i, n+r+1, 1, 0);
        for(i=1; i<=r; i++) for(j=1; j<=n; j++) addEdge(i, r+j, 1, _abs(xr[i]-xc[j])+_abs(yr[i]-yc[j]));
        mcmf(cost);
        printf("%d\n", cost);
    }
    return 0;
}
