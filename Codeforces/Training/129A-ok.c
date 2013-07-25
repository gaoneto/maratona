#include <stdio.h>

int main()
{
    int i, n, a[101], sum=0, resp=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    for(i=0; i<n; i++) if((sum-a[i])%2==0) resp++;
    printf("%d", resp);
    return 0;
}
