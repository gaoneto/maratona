#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int v[2][1001];
int sz[2];

int main() {
    int n[2], m;
    int t=1;
    while(scanf("%d%d%d", &n[0], &n[1], &m) && n[0]) {
        printf("Case %d:\n", t++);
        for(int i=0;i<2;i++) for(int j=0;j<n[i];j++) v[i][j] = -1;
        sz[0] = sz[1] = 0;
        while(m--) {
            int x;
            scanf("%d", &x);
            int i=0;
            while(1) {
                int ind = x%n[i];
                if(v[i][ind] == -1) {
                    v[i][ind] = x;
                    sz[i]++;
                    break;
                }
                else {
                    swap(v[i][ind], x);
                    i = 1-i;
                }
            }
        }
        for(int i=0;i<2;i++) if(sz[i]) {
            printf("Table %d\n", i+1);
            for(int j=0;j<n[i];j++) if(v[i][j] != -1) printf("%d:%d\n", j, v[i][j]);
        }
    }
    return 0;
}
