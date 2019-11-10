#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>

using namespace std;

int dp[1010][1010], lcsuf[1010][1010];

int main()
{
    int i, j, n, m, k, l;
    char s1[1010], s2[1010];
    while(scanf("%d", &k) && k)
    {
        scanf("%s %s", s1, s2);
        n=strlen(s1);
        m=strlen(s2);
        for(i=0; i<=n; i++) dp[i][0]=lcsuf[i][0]=0;
        for(i=0; i<=m; i++) dp[0][i]=lcsuf[0][i]=0;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                lcsuf[i][j]=0;
                if(s1[i-1]==s2[j-1])
                {
                    lcsuf[i][j]=lcsuf[i-1][j-1]+1;
                    if(lcsuf[i][j]>=k)
                        for(l=k; l<=lcsuf[i][j]; l++)
                            dp[i][j]=max(dp[i][j], dp[i-l][j-l]+l);
                }
            }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
