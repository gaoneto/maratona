#include <stdio.h>
#define INF 1000000000

int main()
{
    int r, c, k, i, j, l, m, dp[310][310], aux, minimo, cur, mindif[310];
    char a[310][310];
    while(scanf("%d %d %d", &r, &c, &k) && (r || c || k))
    {
        for(i=1; i<=r; i++)
            scanf("%s", a[i]);
        for(i=0; i<=r; i++)
        {
            dp[0][i]=0;
            mindif[i]=INF;
        }
        for(i=0; i<=c; i++) dp[i][0]=0;
        for(i=1; i<=r; i++)
            for(j=1; j<=c; j++)
            {
                aux=0;
                if(a[i][j-1]=='.') aux=1;
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+aux;
            }
        minimo=INF;
        for(i=1; i<=r; i++)
            for(j=i; j<=r; j++)
            {
                l=m=1;
                cur=0;
                while(m!=c+1)
                {
                    cur=dp[j][m]-dp[i-1][m]-dp[j][l-1]+dp[i-1][l-1];
                    if(cur>=k)
                    {
                        if((j-i+1)*(m-l+1)<minimo) minimo=(j-i+1)*(m-l+1);
                        if((m-l)<mindif[j-i])
                        {
                            mindif[j-i]=m-l;
                            if(!mindif[j-i]) break;
                        }
                        l++;
                    }
                    else
                    {
                        if((m-l)>=mindif[j-i]) l++;
                        m++;
                    }   
                }
            }
        printf("%d\n", minimo);
    }
    return 0;    
}
