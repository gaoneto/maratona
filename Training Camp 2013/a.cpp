#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define INF 1000000000000000000ll
typedef long long ll;
typedef pair<ll, int> pii;

int n, park;
map<string, int> id;
ll adj[22][22], dist[22];
int vis[22];

ll mst(int ind) {
    priority_queue<pii> q;
    for(int i=0;i<n;i++) if(i != park) {
        vis[i]=0;
        if(ind & (1<<i)) {
            q.push(pii(0, i));
            dist[i]=0;
        }
        else {
            dist[i]=INF;
        }
    }
    ll ret=0;
    while(!q.empty()) {
        int v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        ret += dist[v];
        for(int u=0;u<n;u++) if(u != park) {
            ll d = adj[v][u];
            if(dist[u] > d) {
                dist[u] = d;
                q.push(pii(-d, u));
            }
        }
    }
    return ret;
}

int main() {
    int m;
    n=0;
    cin>>m;
    for(int i=0;i<22;i++) for(int j=0;j<22;j++) adj[i][j]=INF;
    for(int i=0;i<22;i++) adj[i][i]=0;
    for(int i=0;i<m;i++) {
        string s1, s2;
        int a, b;
        ll d;
        cin>>s1>>s2>>d;
        if(id.count(s1)) a = id[s1];
        else {
            id[s1] = n;
            if(s1 == "Park") park=n;
            a = n++;
        }
        if(id.count(s2)) b = id[s2];
        else {
            id[s2] = n;
            if(s2 == "Park") park=n;
            b = n++;
        }
        adj[a][b] = adj[b][a] = min(adj[a][b], d);
    }
    int s;
    cin>>s;
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(k == park) continue;
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    }
    ll ans=INF;
    for(int i=1;i<1<<n;i++) {
        if(i & (1<<park)) continue;
        if(__builtin_popcount(i) > s) continue;
        ll d2 = 0;
        for(int j=0;j<n;j++) if(i & (1<<j)) d2 += adj[j][park];
        if(d2 > ans) continue;
        ll d1 = mst(i);
        ans = min(ans, d1+d2);
    }
    cout<<"Total miles driven: "<<ans<<endl;
    return 0;
}
