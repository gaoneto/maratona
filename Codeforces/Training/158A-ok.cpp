#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int k, n, a[51], i;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    if(!a[n-k])
    {
        for(i=n-k; i<n && !a[i]; i++);
        if(i==n) printf("0");
        else printf("%d", n-i);
    }
    else
    {
        for(i=n-k; i>=0 && a[i]==a[n-k]; i--);
        printf("%d", n-i-1);
    }
    return 0;
}
