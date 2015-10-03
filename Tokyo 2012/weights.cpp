#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int pi[N], rank[N];
map<int, int> adj[N];
map<int, int>::iterator it;

int FindSet(int x) { return pi[x]==x ? x : pi[x]=FindSet(pi[x]); }

void Union(int x, int y, int w) {
    int px=FindSet(x), py=FindSet(y);
    if(px==py) return;
    int wx=adj[px][x], wy=adj[py][y];
    if(rank[px]>rank[py]) {
        pi[py]=px;
        for(it=adj[py].begin(); it!=adj[py].end(); it++) adj[px][it->first]=wx+w-wy+it->second;
    }
    else {
        pi[px]=py;
        for(it=adj[px].begin(); it!=adj[px].end(); it++) adj[py][it->first]=wy-w-wx+it->second;
        if(rank[px]==rank[py]) rank[py]++;
    }
}

int main() {
    int n, m, a, b, w;
    char op[2];
    while(scanf("%d %d", &n, &m) && (n || m)) {
        for(int i=0; i<n; i++) adj[i].clear(), pi[i]=i, rank[i]=0;
        for(int i=0; i<m; i++) {
            scanf("%s %d %d", op, &a, &b);
            a--, b--;
            if(op[0]=='!') {
                scanf("%d", &w);
                adj[b][a]=w;
                if(FindSet(b)!=FindSet(a)) Union(b, a, w);
            }
            else {
                if(FindSet(b)!=FindSet(a)) printf("UNKNOWN\n");
                else {
                    int p=FindSet(a);
                    int wa=adj[p][a], wb=adj[p][b];
                    printf("%d\n", wa-wb);
                }
            }
        }
    }
    return 0;
}
