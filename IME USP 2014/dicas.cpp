#include <bits/stdc++.h>

using namespace std;

int v[111111];
vector <int> ans;

int main() {
    int n, a, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        memset(v,0,sizeof(v));
        ans.clear();
        for(int i=0;i<n;i++) {
            scanf("%d", &a);
            if(v[a] == 0) {
                v[a] = 1;
                ans.push_back(a);
            }
        }
        printf("%d", ans[0]);
        for(int i=1;i<k;i++) printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
