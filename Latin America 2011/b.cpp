#include <stdio.h>
#include <iostream>
#define MAX 1010

using namespace std;

int n, dp[MAX][MAX], ball[MAX][MAX];

int main()
{
    int i, j, resp, col;
	while(scanf("%d", &n) && n)
    {
		memset(dp, 0, sizeof(dp));
		for(i=0; i<n; i++) for(j=0; j<=i; j++) scanf("%d", &ball[i-j+1][j+1]);
		n++;
		for(i=1; i<n; i++) for(j=1; j<=n-i; j++) dp[i][j]=ball[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		resp=0;
		for(i=1; i<n; i++)
			for(j=n-i; j>0; j--)
            {
				col=dp[i][j]-dp[i][j-1];
				resp=max(resp, dp[i][j]+dp[i-1][j+1]);
				dp[i][j]=max(max(col, col+dp[i-1][j+1]), max(dp[i-1][j], dp[i][j+1]+col));
			}
		printf("%d\n", resp);
	}
	return 0;
}
