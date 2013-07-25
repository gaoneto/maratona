#include <stdio.h>

int main()
{
    int i, j, n, h[50], a[50], resp=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &h[i], &a[i]);
    for(i=0; i<n; i++) for(j=0; j<n; j++) if(h[i]==a[j]) resp++;
    printf("%d", resp);
    return 0;
}
