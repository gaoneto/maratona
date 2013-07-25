#include <stdio.h>

int main()
{
    int i, n, p, g[101];
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &p);
        g[p]=i+1;
    }
    printf("%d", g[1]);
    for(i=2; i<=n; i++) printf(" %d", g[i]);
    return 0;
}
