#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <utility>
 
using namespace std;
 
int main()
{
    int i, j, k, n, resp, aux, aux1;
    long long x[1010], y[1010], d, p[1010];
    double dist;
    while(scanf("%d", &n) && n)
    {
        resp=0;
        for(i=0; i<n; i++)
            scanf("%lld %lld", &x[i], &y[i]);
        for(i=0; i<n; i++)
        {
            aux1=0;
            for(j=0; j<n; j++)
                if(j!=i)
                {
                    d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    p[aux1++]=d;
                }
            sort(p, p+aux1);
            aux=1;
            for(j=1; j<n-1; j++)
            {
                if(p[j]==p[j-1])
                {
                    aux++;
                    if(j==n-2) resp+=(aux*(aux-1)/2);
                }
                else
                {
                    resp+=(aux*(aux-1)/2);
                    aux=1;
                }
            }
        }
        printf("%d\n", resp);
    }
    return 0;
}
