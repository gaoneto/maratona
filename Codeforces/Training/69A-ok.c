#include <stdio.h>

int main()
{
    int i, n, x, y, z, sx=0, sy=0, sz=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        sx+=x;
        sy+=y;
        sz+=z;
    }
    if(!sx && !sy && !sz) printf("YES");
    else printf("NO");
    return 0;
}
