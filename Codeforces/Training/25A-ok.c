#include <stdio.h>

int main()
{
    int i, e, o, ce=0, n, a;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        if(a%2==0)
        {
            ce++;
            e=i;
        }
        else o=i;
    }
    printf("%d", ce==1 ? e : o);
}
