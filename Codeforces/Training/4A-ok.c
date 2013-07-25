#include <stdio.h>

int main()
{
    int w;
    scanf("%d", &w);
    printf("%s", (w%2==1 || w==2) ? "NO" : "YES");
    return 0;
}
