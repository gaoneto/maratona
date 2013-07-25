#include <cstdio>

int main()
{
    int n, d[101], a, b, resp=0, i;
    scanf("%d", &n);
    for(i=1; i<n; i++) scanf("%d", &d[i]);
    scanf("%d %d", &a, &b);
    for(i=a; i<b; i++) resp+=d[i];
    printf("%d", resp);
    return 0;
}
