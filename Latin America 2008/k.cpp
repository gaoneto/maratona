#include <stdio.h>
#include <iostream>

using namespace std;

int x[10010];
bool tem[10000010];

int main()
{
    int i, j, k, sum, n, maximo, lados, vert, ponto, flag, pos;
    while(scanf("%d", &n) && n)
    {
        sum=maximo=ponto=0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &x[i]);
            sum+=x[i];
            if(x[i]>maximo) maximo=x[i];
        }
        for(i=0; i<sum; i++) tem[i]=false;
        for(i=0; i<n; i++)
        {
            tem[ponto]=true;
            ponto+=x[i];
        }
        vert=-1;
        lados=sum/maximo;
        for(i=lados; i>2; i--)
        {
            if(sum%i!=0) continue;
            flag=0;
            lados=sum/i;
            for(j=0; j<lados; j++)
            {
                pos=1;
                k=j;
                while(k<sum)
                {
                    if(!tem[k])
                    {
                        pos=0;
                        break;
                    }
                    k+=lados;
                }
                if(pos)
                {
                    vert=i;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(vert==-1) printf("-1\n");
        else printf("%d\n", n-vert);
    }
    return 0;
}
