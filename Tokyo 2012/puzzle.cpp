#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int N=55;

char s[N][N];
int r, c, d[N][N][4], vis[N][N][4], ds[N][N];
int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int in(int x, int y) { return x>=0 && x<r && y>=0 && y<c; }

int is_kpos(int u, int v, int ki, int kj) {
    if(u==ki && v==kj) return 1;
    if(u==ki+1 && v==kj) return 1;
    if(u==ki && v==kj+1) return 1;
    if(u==ki+1 && v==kj+1) return 1;
    return 0;
}

int bfs(int si, int sj, int ei, int ej, int ki, int kj) {
    queue<pair<int, int> > q;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) ds[i][j]=-1;
    ds[si][sj]=0;
    if(si==ei && sj==ej) return ds[si][sj];
    q.push(make_pair(si, sj));
    while(!q.empty()) {
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nu=u+dx[i], nv=v+dy[i];
            if(!in(nu, nv)) continue;
            if(is_kpos(nu, nv, ki, kj)) continue;
            if(s[nu][nv]=='*') continue;
            if(ds[nu][nv]==-1) {
                ds[nu][nv]=ds[u][v]+1;
                if(nu==ei && nv==ej) return ds[nu][nv];
                q.push(make_pair(nu, nv));
            }
        }
    }
    return INF;
}

int dijkstra(int ki, int kj, int s1i, int s1j, int s2i, int s2j) {
    priority_queue<pair<int, pair<int, pair<int, int> > > > q;
    int f=0;
    d[ki][kj][0]=0;
    q.push(make_pair(-d[ki][kj][0], make_pair(ki, make_pair(kj, 0))));
    while(!q.empty()) {
        int u=q.top().second.first;
        int v=q.top().second.second.first;
        int dir=q.top().second.second.second;
        q.pop();
        if(vis[u][v][dir]) continue;
        if(!u && !v) return d[u][v][dir];
        vis[u][v][dir]=1;
        for(int i=0; i<4; i++) {
            int nu=u+dx[i], nv=v+dy[i];
            int w, e1i, e1j, e2i, e2j;
            if(!i) e1i=nu+1, e1j=nv, e2i=nu+1, e2j=nv+1;
            else if(i==1) e1i=nu, e1j=nv, e2i=nu+1, e2j=nv;
            else if(i==2) e1i=nu, e1j=nv, e2i=nu, e2j=nv+1;
            else e1i=nu, e1j=nv+1, e2i=nu+1, e2j=nv+1;
            if(f) {
                if(!dir) s1i=u-1, s1j=v, s2i=u-1, s2j=v+1;
                else if(dir==1) s1i=u, s1j=v+2, s2i=u+1, s2j=v+2;
                else if(dir==2) s1i=u+2, s1j=v, s2i=u+2, s2j=v+1;
                else s1i=u, s1j=v-1, s2i=u+1, s2j=v-1;
            }
            if(!in(s1i, s1j) || !in(s2i, s2j)) continue;
            if(!in(e1i, e1j) || !in(e2i, e2j)) continue;
            w=min(bfs(s1i, s1j, e1i, e1j, u, v)+bfs(s2i, s2j, e2i, e2j, u, v), bfs(s1i, s1j, e2i, e2j, u, v)+bfs(s2i, s2j, e1i, e1j, u, v));
            if(w>=INF) continue;
            if(d[nu][nv][i]>d[u][v][dir]+w+1) {
                d[nu][nv][i]=d[u][v][dir]+w+1;
                q.push(make_pair(-d[nu][nv][i], make_pair(nu, make_pair(nv, i))));
            }
        }
        f=1;
    }
    return -1;
}

int main() {
    while(scanf("%d %d", &r, &c) && (r || c)) {
        int ki, kj, s1i=-1, s1j, s2i, s2j, f=0;
        for(int i=0; i<r; i++) {
            scanf("%s", s[i]);
            for(int j=0; j<c; j++) {
                for(int k=0; k<4; k++) d[i][j][k]=INF, vis[i][j][k]=0;
                if(s[i][j]=='X') {
                    if(!f) ki=i, kj=j;
                    f=1;
                    s[i][j]='o';
                }
                if(s[i][j]=='.') {
                    if(s1i==-1) s1i=i, s1j=j;
                    else s2i=i, s2j=j;
                }
            }
        }
        printf("%d\n", dijkstra(ki, kj, s1i, s1j, s2i, s2j));
    }
    return 0;
}
