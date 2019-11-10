#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int t[1111][1111];

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, -1, 0, -1, 1, 0, 1, -1};

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        vector<pii> v;
        for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) t[i][j] = -1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &t[i][j]);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
            int k=0;
            for(k=0;k<8;k++) {
                if(t[i][j] <= t[i+dx[k]][j+dy[k]]) break;
            }
            if(k == 8) v.push_back(pii(i, j));
        }
        if(v.size() == 0) printf("-1\n\n");
        else {
            for(int i=0;i<v.size();i++) printf("%d %d\n", v[i].first, v[i].second);
            printf("\n");
        }
    }
    return 0;
}
