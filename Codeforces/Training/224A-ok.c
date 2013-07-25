#include <stdio.h>

int main()
{
    int x, y, z, a, b, c;
    scanf("%d %d %d", &x, &y, &z);
    for(a=1; a<10001; a++) if(x%a==0 && y%a==0)
    {
        b=x/a;
        c=y/a;
        if(b*c==z) break;
    }
    printf("%d", 4*(a+b+c));
    return 0;
}
