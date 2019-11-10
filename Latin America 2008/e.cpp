#include <stdio.h>

int main()
{
    int n, d[1000], m[1000], y[1000], c[1000], i, dias, cons;
    while(scanf("%d", &n)==1 && n)
    {
        dias=cons=0;
        for(i=0; i<n; i++)
            scanf("%d %d %d %d", &d[i], &m[i], &y[i], &c[i]);
        for(i=0; i<n-1; i++)
        {
            if(y[i+1]==y[i])
            {
                if(m[i+1]==m[i])
                {
                    if(d[i+1]-d[i]==1)
                    {
                        dias++;
                        cons+=c[i+1]-c[i];
                    }
                }
                else
                {
                    if(m[i+1]-m[i]==1)
                    {
                        if(m[i]==1 || m[i]==3 || m[i]==5 || m[i]==7 || m[i]==8 || m[i]==10)
                        {
                            if(d[i]-d[i+1]==30)
                            {
                                dias++;
                                cons+=c[i+1]-c[i];
                            }
                        }
                        else if(m[i]==4 || m[i]==6 || m[i]==9 || m[i]==11)
                             {
                                 if(d[i]-d[i+1]==29)
                                 {
                                     dias++;
                                     cons+=c[i+1]-c[i];
                                 }
                             }    
                             else
                             {
                                 if(m[i]==2)
                                 {
                                     if(d[i+1]==1 && d[i]==28)
                                     {
                                         dias++;
                                         cons+=c[i+1]-c[i];
                                     }
                                     if((y[i]%4==0 && y[i]%100!=0) || y[i]%400==0)
                                     {
                                         if(d[i+1]==1 && d[i]==29)
                                         {
                                             dias++;
                                             cons+=c[i+1]-c[i];
                                         }
                                     }
                                 }
                             }
                    }
                }
            }
            else
            {
                if(m[i+1]==1 && d[i+1]==1 && m[i]==12 && d[i]==31)
                {
                    dias++;
                    cons+=c[i+1]-c[i];
                }
            }
        }
        printf("%d %d\n", dias, cons);
    }
    return 0;    
}
