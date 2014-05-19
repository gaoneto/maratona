#include <bits/stdc++.h>
using namespace std;
    
int n, m, L, T=0;
int x[16], y[16], vis[222][222];
char tab[222][222];

int dx[] = {-1, 1, 1, -1};
int dy[] = {1, -1, 1, -1};

int valid(int mask, int esp, int dir) {
    T++;
    for(int i=0;i<L;i++) if(mask & (1<<i)) {
        if(i == esp) {
            int nx = x[i] + dx[dir];
            int ny = y[i] + dy[dir];
            vis[x[i]][y[i]] = T;
            if(nx >= 0 && nx < n) {
                if(tab[nx][y[i]] == '#') return 0;
                vis[nx][y[i]] = T;
            }
            if(ny >= 0 && ny < m) {
                if(tab[x[i]][ny] == '#') return 0;
                vis[x[i]][ny] = T;
            }
        }
        else {
            int nx = x[i] + dx[0];
            int ny = y[i] + dy[0];
            vis[x[i]][y[i]] = T;
            if(nx >= 0 && nx < n) {
                if(tab[nx][y[i]] == '#') return 0;
                vis[nx][y[i]] = T;
            }
            if(ny >= 0 && ny < m) {
                if(tab[x[i]][ny] == '#') return 0;
                vis[x[i]][ny] = T;
            }
        }
    }
    for(int i=0;i<L;i++) if(vis[x[i]][y[i]] != T) return 0;
    return 1;
}

int main() {
    while(cin>>n>>m && n) {
        for(int i=0;i<n;i++) {
            scanf("%s", tab[i]);
        }
        L=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tab[i][j] == '.') {
            x[L] = i;
            y[L] = j;
            L++;
        }
        if(L == 0) {
            cout << 0 << "\n";
        }
        else {
            int ans=1000;
            for(int i=0;i<1<<L;i++) {
                int len = __builtin_popcount(i);
                if(len >= ans) continue;
                for(int j=0;j<L;j++) if(i & (1<<j)) {
                    for(int dir=0;dir<4;dir++) {
                        if(valid(i, j, dir)) ans = len;
                    }
                }
            }
            if(ans == 1000) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }
    return 0;
}
