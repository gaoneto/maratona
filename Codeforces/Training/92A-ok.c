#include <stdio.h>

int main()
{
    int i, n, resp=1, m;
    scanf("%d %d", &n, &m);
    while(m>=resp)
    {
        m-=resp;
        resp=(resp+1)%(n+1);
    }
    printf("%d", m);
    return 0;
}
