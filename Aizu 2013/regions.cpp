#include <bits/stdc++.h>
using namespace std;

const int M=1e6+10;
map<int, int> idx, idy;
const int N = 250;
int G[N][N][2], l[N], r[N], t[N], b[N], vis[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int a, int b) {
    vis[a][b] = 1;
    for(int i=0;i<4;i++) {
        int na = a+dx[i];
        int nb = b+dy[i];
        if(vis[na][nb] || na < 0 || na >= N || nb < 0  || nb >= N) continue;
        int ca, cb;
        if(i < 2) ca = na, cb = nb;
        else ca = a, cb = b;
        if(!G[ca][cb][i%2]) dfs(na, nb);
    }
}

int main() {
    int n;
    while(cin>>n && n) {
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        vector<int> vx, vy;
        idx.clear();
        idy.clear();
        for(int i=0;i<n;i++) {
            cin>>l[i]>>t[i]>>r[i]>>b[i];
            vx.push_back(l[i]);
            vx.push_back(r[i]);
            vy.push_back(t[i]);
            vy.push_back(b[i]);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());
        for(int i=0;i<vx.size();i++) idx[vx[i]] = i+1;
        for(int i=0;i<vy.size();i++) idy[vy[i]] = i+1;
        for(int i=0;i<n;i++) {
            for(int j=idy[b[i]];j<idy[t[i]];j++) {
                G[idx[l[i]]][j][0] = 1;
                G[idx[r[i]]][j][0] = 1;
            }
            for(int j=idx[l[i]];j<idx[r[i]];j++) {
                G[j][idy[t[i]]][1] = 1;
                G[j][idy[b[i]]][1] = 1;
            }
        }
        int cc=0;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(!vis[i][j]) dfs(i, j), cc++;
        cout << cc << endl;
    }
    return 0;
}
