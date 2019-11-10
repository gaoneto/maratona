#include <stdio.h>

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
        if(n!=0)
            printf("%d\n", n*(n+1)*(2*n+1)/6);
    }while(n!=0);
    return 0;
}
