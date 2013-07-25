#include <stdio.h>

int mod(int a) { return ((a>0) ? a : -a); }

int main()
{
    int i, j, x, y, a;
    for(i=0; i<5; i++) for(j=0; j<5; j++) 
    {
        scanf("%d", &a);
        if(a)
        {
            x=i+1;
            y=j+1;
        }
    }
    printf("%d", mod(x-3)+mod(y-3));
    return 0;
}
