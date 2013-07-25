#include <stdio.h>

int main()
{
    int i, n, a, min=200, max=0, imax, imin;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        if(a>max)
        {
            max=a;
            imax=i;
        }
        if(a<=min)
        {
            min=a;
            imin=i;
        }
    }
    if(imax<imin) printf("%d", imax+n-imin-1);
    else printf("%d", imax+n-imin-2);
    return 0;
}
