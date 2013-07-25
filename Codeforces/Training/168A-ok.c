#include <stdio.h>
#include <math.h>

int main()
{
    double n, x, y;
    scanf("%lf %lf %lf", &n, &x, &y);
    if(n*y<=100*x) printf("0");
    else printf("%.0lf", ceil((n*y-100*x)/100.0));
    return 0;
}
