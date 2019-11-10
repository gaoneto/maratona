#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int dp[2][22][(1<<20)+1], d[22][22], n;

int main()
{
    int m, u, v, t, T=1, i, j, k, l;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        int ans=INF;
        for(i=0; i<n; i++) for(j=0; j<n; j++) d[i][j]=INF;
        for(i=0; i<2; i++) for(j=0; j<n; j++) for(k=0; k<(1<<n); k++) dp[i][j][k]=INF;
        for(i=0; i<n; i++) d[i][i]=0;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &t);
            d[u][v]=d[v][u]=t;
        }
        for(k=0; k<n; k++) for(i=0; i<n; i++) for(j=0; j<n; j++) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
        dp[0][0][1]=dp[1][n-1][1<<(n-1)]=0;
        for(k=0; k<2; k++) for(i=1; i<(1<<n); i++) for(j=0; j<n; j++) if((1<<j)&i)
        {
            for(l=0; l<n; l++) if(!((1<<l)&i)) dp[k][l][i|(1<<l)]=min(dp[k][l][i|(1<<l)], dp[k][j][i]+d[j][l]);
        }
        if(n==3) ans=2*(d[0][1]+d[1][2]);
        else
        {
            for(i=1; i<(1<<n); i++) if(__builtin_popcount(i)==(n-2)/2 && !(i&1) && !(i&(1<<(n-1))))
            {
                vector<int> v0, v1;
                for(j=1; j<n-1; j++)
                {
                    if((1<<j)&i) v1.push_back(j);
                    else v0.push_back(j);
                }
                int m1=i, m2=(1<<n)-1-(1<<(n-1))-1-i;
                for(j=0; j<v1.size(); j++) for(k=0; k<v1.size(); k++) for(l=0; l<v0.size(); l++) for(m=0; m<v0.size(); m++)
                {
                    ans=min(ans, dp[0][v1[j]][m1|1]+d[v1[j]][v0[l]]+dp[1][v0[l]][m2|(1<<(n-1))]+dp[1][v1[k]][m1|(1<<(n-1))]+d[v1[k]][v0[m]]+dp[0][v0[m]][m2|1]);
                }
            }
        }
        printf("Case %d: %d\n", T++, ans);
    }
    return 0;
}
