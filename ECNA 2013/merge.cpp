#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N=1e3+10;
int ans, dp[N][8], v[N][3];

int main() {
    int n, t=1;
    while(scanf("%d", &n) && n) {
        for(int i=0;i<3;i++) for(int j=1;j<=n;j++) scanf("%d", &v[j][i]);
        for(int i=1;i<=n;i++) for(int mask=0;mask<8;mask++) {
            dp[i][mask]=0;
            for(int old=0;old<8;old++) {
                int val = dp[i-1][old];
                int valid=1;
                for(int row=0;row<3;row++) {
                    if(mask & (1<<row)) {
                        if(old & (1<<row)) valid=0;
                        else val += v[i][row] * v[i-1][row];
                    }
                }
                if(valid) dp[i][mask] = max(dp[i][mask], val);
            }
            if((mask&1) && (mask&2)) {
                for(int old=0;old<8;old++) {
                    int val = dp[i-1][old] + v[i][0]*v[i][1];
                    if(mask & 4) {
                        if(old & 4) continue;
                        dp[i][mask] = max(dp[i][mask], val + v[i][2]*v[i-1][2]);
                    }
                    else {
                        dp[i][mask] = max(dp[i][mask], val);
                    }
                }
            }
            if((mask&2) && (mask&4)) {
                for(int old=0;old<8;old++) {
                    int val = dp[i-1][old] + v[i][1]*v[i][2];
                    if(mask & 1) {
                        if(old & 1) continue;
                        dp[i][mask] = max(dp[i][mask], val + v[i][0]*v[i-1][0]);
                    }
                    else {
                        dp[i][mask] = max(dp[i][mask], val);
                    }
                }
            }
        }
        ans=0;
        for(int i=0;i<8;i++) ans = max(ans, dp[n][i]);
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}
