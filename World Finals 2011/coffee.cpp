#include <bits/stdc++.h>
#define OFF 1000
using namespace std;

const int N=5e5+10;

int x[N], y[N], xn[N], yno[N], a[3333][3333], dp[3333][3333];

int sum(int a, int b, int c, int d) { return dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1]; }

int main()
{
    int i, dx, dy, n, q, m, j, t=1;
    while(scanf("%d %d %d %d", &dx, &dy, &n, &q) && dx)
    {
        int xm=dx-1+OFF, ym=dx+dy+OFF;
        for(i=0; i<n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            xn[i]=x[i]-y[i];
            yno[i]=x[i]+y[i];
            a[OFF+xn[i]][OFF+yno[i]]=1;
        }
        for(i=1; i<=xm; i++) for(j=1; j<=ym; j++) dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        printf("Case %d:\n", t++);
        for(i=0; i<q; i++)
        {
            scanf("%d", &m);
            int ans=-1, xa=1, ya=1;
            for(int k=1; k<=ym; k++) for(j=1; j<=xm; j++)
            {
                int s=sum(max(1, j-m), max(1, k-m), min(xm, j+m), min(ym, k+m));
                if(s>=ans && (j+k)%2==0)
                {
                    int auxx=(j+k)/2-OFF;
                    int auxy=(k-j)/2;
                    if(auxx>=1 && auxy>=1 && auxx<=dx && auxy<=dy)
                    {
                        if(s>ans)
                        {
                            ans=s;
                            xa=auxx;
                            ya=auxy;
                        }
                        else if(auxy<ya)
                        {
                            xa=auxx;
                            ya=auxy;
                        }
                        else if(auxy==ya && auxx<xa)
                        {
                            xa=auxx;
                            ya=auxy;
                        }
                    }
                }
            }
            printf("%d (%d,%d)\n", ans, xa, ya);
        }
        for(i=0; i<n; i++) a[OFF+xn[i]][OFF+yno[i]]=0;
    }
    return 0;
}
