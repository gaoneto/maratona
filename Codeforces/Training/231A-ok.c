#include <stdio.h>

int main()
{
    int i, j, n, a, resp=0, cont;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        cont=0;
        for(j=0; j<3; j++)
        {
            scanf("%d", &a);
            if(a) cont++;
        }
        if(cont>1) resp++;
    }
    printf("%d", resp);
    return 0;
}
