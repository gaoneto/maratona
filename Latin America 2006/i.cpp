#include <stdio.h>
#include <iostream>
#define INF 1000000000

using namespace std;

int dp[300][300], dpmin[300][300];

int main()
{
    int i, j, k, s, b, x[300], y[300], resp, ini;
    while(scanf("%d %d", &s, &b) && (s || b))
    {
        for(i=0; i<s; i++) scanf("%d", &x[i]);
        for(i=0; i<b; i++) scanf("%d", &y[i]);
        resp=INF;
        for(ini=0; ini<s; ini++)
        {
            dp[0][0]=dpmin[0][0]=(x[ini]+x[(ini+1)%s])*y[0];
            for(j=1; j<s; j++)
            {
                dp[0][j]=INF;
                dpmin[0][j]=min(dpmin[0][j-1], dp[0][j]);
            }
            for(j=1; j<b; j++)
            {
                dpmin[j][2*j-1]=dpmin[j][2*j-2]=INF;
                for(k=2*j; k<s-2*(b-j-1)-1; k++)
                {
                    dp[j][k]=dpmin[j-1][k-2]+(x[(ini+k)%s]+x[(ini+k+1)%s])*y[j];
                    dpmin[j][k]=min(dpmin[j][k-1], dp[j][k]);
                }
            }
            for(j=2*b-2; j<s-1; j++) resp=min(resp, dp[b-1][j]);
        }
        printf("%d\n", -resp);
    }
    return 0;
}
