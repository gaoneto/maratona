#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
char s[N][N];
int dp[N][N];

int main() {
	int n, m, ans=0;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%s", s[i]);
	for(int i=0; i<n; i++) {
		dp[i][m-1]=1;
		for(int j=m-2; j>=0; j--) {
			if(s[i][j]==s[i][j+1]) dp[i][j]=dp[i][j+1]+1;
			else dp[i][j]=1;
		}
	}
	for(int j=0; j<m; j++) {
		for(int i=0; i<n; i++) {
			if(ans>dp[i][j]*dp[i][j]) continue;
			int _min=dp[i][j];
			for(int k=0; k<dp[i][j] && i+k<n; k++) {
				if(dp[i+k][j]>=k+1 && dp[i+k][j]>=_min) ans=max(ans, (k+1)*(k+1));
				else break;
				_min=min(_min, dp[i+k][j]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
