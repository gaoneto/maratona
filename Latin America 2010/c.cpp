#include <stdio.h>
#include <math.h>
#define EPS 1e-6

double x[105], y[105];

int colineares(int i, int j, int k)
{
    if(fabs(x[i]*y[j]+y[i]*x[k]+x[j]*y[k]-x[k]*y[j]-x[i]*y[k]-x[j]*y[i])<EPS) return 1;
    return 0;
}

int main()
{
    int i, j, k, l, n, max, cont;
    double a, xc, yc, r;
    while(scanf("%d", &n) && n)
    {
        for(i=0; i<n; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        max=2;
        if(n==1) max=1;
        else
        {
            for(i=0; i<n; i++)
                for(j=i+1; j<n; j++)
                    for(k=j+1; k<n; k++)
                        if(!colineares(i, j, k))
                        {
                            a=2*((x[i]-x[j])*(y[i]-y[k])-(x[i]-x[k])*(y[i]-y[j]));
                            xc=((y[i]*y[i]-y[j]*y[j]+x[i]*x[i]-x[j]*x[j])*(y[i]-y[k])-(y[i]*y[i]-y[k]*y[k]+x[i]*x[i]-x[k]*x[k])*(y[i]-y[j]))/a;
                            if(y[i]==y[j]) yc=(y[i]*y[i]-y[k]*y[k]+x[i]*x[i]-x[k]*x[k]-2*xc*(x[i]-x[k]))/(2*(y[i]-y[k]));
                            else yc=(y[i]*y[i]-y[j]*y[j]+x[i]*x[i]-x[j]*x[j]-2*xc*(x[i]-x[j]))/(2*(y[i]-y[j]));
                            r=(x[i]-xc)*(x[i]-xc)+(y[i]-yc)*(y[i]-yc);
                            cont=3;
                            if(cont>max) max=cont;
                            for(l=k+1; l<n; l++)
                                if(fabs((x[l]-xc)*(x[l]-xc)+(y[l]-yc)*(y[l]-yc)-r)<EPS)
                                {
                                    cont++;
                                    if(cont>max) max=cont;
                                }
                        }
        }
        printf("%d\n", max);
    }
    return 0;
}
