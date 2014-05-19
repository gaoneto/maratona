#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

string t[111];
int d[5][111][111], vis[111][111];
int n, m, k;
pair<int,int> a[5], s;
int p[5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int x, int y, int o) {
    queue <pair<int,int> > q;
    memset(vis,0,sizeof(vis));
    q.push(mp(x,y));
    d[o][x][y] = 0;
    vis[x][y] = 1;
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = u.ff + dx[i];
            int ny = u.ss + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(!vis[nx][ny] && t[nx][ny] != '#') {
                    vis[nx][ny] = 1;
                    d[o][nx][ny] = d[o][u.ff][u.ss] + 1;
                    q.push(mp(nx,ny));
                }
            }
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &m) && n) {
        for(int i=0;i<n;i++) cin >> t[i];
        cin >> k;
        for(int i=0;i<k;i++) cin >> a[i].ff >> a[i].ss;
        for(int i=0;i<k;i++) { a[i].ff--; a[i].ss--; }
        for(int i=0;i<k;i++) p[i] = i;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(t[i][j] == '@') s = mp(i,j);
        for(int i=0;i<k;i++) for(int j=0;j<n;j++) for(int l=0;l<m;l++) d[i][j][l] = 1e6;
        for(int i=0;i<k;i++) bfs(a[i].ff, a[i].ss, i);
        int ret = 1e6;
        do {
            int r = d[p[0]][s.ff][s.ss];
            for(int i=1;i<k;i++) r += d[p[i]][a[p[i-1]].ff][a[p[i-1]].ss];
            ret = min(ret,r);
        } while(next_permutation(p,p+k));
        cout << (ret == 1e6 ? -1 : ret) << endl;        
    }
    return 0;
}
