#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int vis[25][25][25][25][33], n, m, rj, cj, rb, cb, rx, cx;
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
char s[33][33];

struct state {
    int rj, cj, rb, cb, mask;
    state(int rj, int cj, int rb, int cb, int mask): rj(rj), cj(cj), rb(rb), cb(cb), mask(mask) {}
    state() {}
};

int in(int x, int y) { return x>=0 && x<n && y>=0 && y<m; }

int main() {
    while(scanf("%d %d", &n, &m)!=EOF) {
        int cnt=0, door=INF, mov=INF;
        for(int i=0; i<n; i++) {
            scanf("%s", s[i]);
            for(int j=0; j<m; j++) {
                if(s[i][j]=='#') {
                    s[i][j]='0'+cnt;
                    cnt++;
                }
                if(s[i][j]=='j') rj=i, cj=j, s[i][j]='.';
                if(s[i][j]=='b') rb=i, cb=j, s[i][j]='.';
                if(s[i][j]=='x') rx=i, cx=j, s[i][j]='.';
            }
        }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) for(int k=0; k<n; k++) for(int l=0; l<m; l++) for(int u=0; u<(1<<cnt); u++) vis[i][j][k][l][u]=-1;
        queue<state> q;
        vis[rj][cj][rb][cb][0]=0;
        q.push(state(rj, cj, rb, cb, 0));
        while(!q.empty()) {
            state u=q.front();
            q.pop();
            int bits=__builtin_popcount(u.mask), movs=vis[u.rj][u.cj][u.rb][u.cb][u.mask];
            if(bits>door || (bits==door && movs>=mov)) continue;
            if(u.rb==rx && u.cb==cx) {
                if(bits<door) door=bits, mov=movs;
                else if(bits==door && movs<mov) mov=movs;
                continue;
            }
            for(int i=0; i<4; i++) {
                int nrj=u.rj+dx[i], ncj=u.cj+dy[i];
                if(in(nrj, ncj)) {
                    if(s[nrj][ncj]=='*') continue;
                    if(nrj==u.rb && ncj==u.cb) {
                        int nrb=u.rb+dx[i], ncb=u.cb+dy[i];
                        if(in(nrb, ncb)) {
                            if(s[nrb][ncb]=='*') continue;
                            if(s[nrb][ncb]=='.' && vis[nrj][ncj][nrb][ncb][u.mask]==-1) {
                                vis[nrj][ncj][nrb][ncb][u.mask]=vis[u.rj][u.cj][u.rb][u.cb][u.mask]+1;
                                q.push(state(nrj, ncj, nrb, ncb, u.mask));
                            }
                            else if(s[nrb][ncb]>='0' && s[nrb][ncb]<='9' && (u.mask&(1<<(s[nrb][ncb]-'0'))) && vis[nrj][ncj][nrb][ncb][u.mask]==-1) {
                                vis[nrj][ncj][nrb][ncb][u.mask]=vis[u.rj][u.cj][u.rb][u.cb][u.mask]+1;
                                q.push(state(nrj, ncj, nrb, ncb, u.mask));
                            }
                        }
                    }
                    else if(s[nrj][ncj]=='.' && vis[nrj][ncj][u.rb][u.cb][u.mask]==-1) {
                        vis[nrj][ncj][u.rb][u.cb][u.mask]=vis[u.rj][u.cj][u.rb][u.cb][u.mask]+1;
                        q.push(state(nrj, ncj, u.rb, u.cb, u.mask));
                    }
                    else if(s[nrj][ncj]>='0' && s[nrj][ncj]<='9' && vis[nrj][ncj][u.rb][u.cb][u.mask|(1<<(s[nrj][ncj]-'0'))]==-1) {
                        vis[nrj][ncj][u.rb][u.cb][u.mask|(1<<(s[nrj][ncj]-'0'))]=vis[u.rj][u.cj][u.rb][u.cb][u.mask]+1;
                        q.push(state(nrj, ncj, u.rb, u.cb, u.mask|(1<<(s[nrj][ncj]-'0'))));
                    }
                }
            }
        }
        if(door==INF) printf("-1\n");
        else printf("%d %d\n", door, mov);
    }
    return 0;
}
