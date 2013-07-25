#include <stdio.h>

char dr[100010];

int main()
{
    int i, k, l, m, n, d, cont=0;
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
    for(i=k; i<=d; i+=k) dr[i]=1;
    for(i=l; i<=d; i+=l) dr[i]=1;
    for(i=m; i<=d; i+=m) dr[i]=1;
    for(i=n; i<=d; i+=n) dr[i]=1;
    for(i=1; i<=d; i++) if(dr[i]) cont++;
    printf("%d", cont);
    return 0;
}
