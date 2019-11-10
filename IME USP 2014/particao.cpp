#include <bits/stdc++.h>
using namespace std;

long long dp[1111][1111], sum[1111];
int v[1111];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=1; i<=n; i++) scanf("%d", &v[i]);
        sort(v+1, v+n+1);
        for(int i=1; i<=n; i++) sum[i]=sum[i-1]+v[i];
        for(int i=1; i<=n; i++) for(int j=i+1;j<=n;j++) dp[i][j] = dp[i][j-1] + (j-i) * v[j] - (sum[j-1] - sum[i-1]);
        long long ans=1e18;
        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) {
            ans = min(ans, dp[i][j] + dp[1][i-1] + dp[j+1][n] + (i-1) * (sum[n] - sum[j]) - (n-j) * sum[i-1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
