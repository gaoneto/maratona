#include <stdio.h>

int main()
{
    int x, i, y, k, n, flag=0;
    scanf("%d %d %d", &y, &k, &n);
    for(i=1; i*k-y<=0; i++);
    for(x=i*k-y; x+y<=n; x+=k)
    {
        printf("%d ", x);
        flag=1;
    }
    if(!flag) printf("-1");
}
