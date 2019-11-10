#include <bits/stdc++.h>
using namespace std;

int dp[1111][1111];

int sum(int a, int b, int c, int d) { return dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1]; }

int main() {
    int n, m, t, x;
    scanf("%d", &t);
    while(t--) {
        int ans=-1e9;
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
            scanf("%d", &x);
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+x;
        }
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) ans=max(ans, sum(i, j, n, m));
        printf("%d\n", ans);
    }
    return 0;
}


