#include <stdio.h>

int main()
{
    int i, b[7], n, resp=0;
    scanf("%d", &n);
    for(i=0; i<7; i++) scanf("%d", &b[i]);
    while(n)
    {
        n-=b[resp%7];
        if(n<=0) break;
        resp++;
    }
    printf("%d", resp%7+1);
    return 0;
}
