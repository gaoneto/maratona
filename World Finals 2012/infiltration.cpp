#include <bits/stdc++.h>
using namespace std;

int n, vis[77];
char mat[77][77];
vector<int> adj[77];
int sz[77];

int go(int tam, int nvis, int imin) {
    for(int i=imin;i<n;i++) if(vis[i] < 100) {
        int oldnvis = nvis;
        if(!vis[i]) nvis++;
        vis[i] += 100;
        for(int ii=0;ii<sz[i];ii++) if(!vis[adj[i][ii]]++) nvis++;
        if(nvis == n) return 1;
        if(tam > 1 && oldnvis != nvis && go(tam-1, nvis, i+1)) return 1; 
        vis[i] -= 100;
        nvis = oldnvis;
        for(int ii=0;ii<sz[i];ii++) vis[adj[i][ii]]--;
    }
    return 0;
}

vector<int> greedy;
int used[77];

int main() {
    int T=1;
    while(scanf("%d", &n) != EOF) {
        for(int i=0;i<n;i++) {
            vis[i]=0;
            adj[i].clear();
        }
        for(int i=0;i<n;i++) scanf("%s", mat[i]);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(mat[i][j]=='1') adj[i].push_back(j);
        for(int i=0;i<n;i++) sz[i] = adj[i].size();
        
        greedy.clear();
        for(int i=0;i<n;i++) used[i]=0;
        int rem=n;
        while(rem) {
            int v, m=-1;
            for(int i=0;i<n;i++) if(!used[i]) {
                int tot=0;
                for(int j=0;j<adj[i].size();j++) {
                    int x = adj[i][j];
                    if(!used[x]) tot++;
                }
                if(tot > m) {
                    m = tot;
                    v = i;
                }
            }
            used[v]=1;
            greedy.push_back(v);
            rem--;
            for(int i=0;i<adj[v].size();i++) {
                int u = adj[v][i];
                if(!used[u]) {
                    used[u]=1;
                    rem--;
                }
            }
        }
        
        int ok=0, tam;
        for(tam=1;tam<greedy.size();tam++) if(go(tam, 0, 0)) {
            printf("Case %d: %d", T++, tam);
            for(int i=0;i<n;i++) if(vis[i] >= 100) printf(" %d", i+1);
            printf("\n");
            ok=1;
            break;
        }
        if(!ok) {
            printf("Case %d: %d", T++, tam);
            for(int i=0;i<tam;i++) printf(" %d", greedy[i]+1);
            printf("\n");
        }
    }
    return 0;
}
