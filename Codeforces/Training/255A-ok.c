#include <stdio.h>

int main()
{
    int i, n, a[21], bi=0, ch=0, ba=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<n; i+=3) ch+=a[i];
    for(i=1; i<n; i+=3) bi+=a[i];
    for(i=2; i<n; i+=3) ba+=a[i];
    if(ch>bi && ch>ba) printf("chest");
    else if(bi>ba) printf("biceps");
    else printf("back");
    return 0;
}
