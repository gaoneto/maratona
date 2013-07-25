#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[101], sum=0, resp=0, maximo=0, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    sort(a, a+n);
    for(i=n-1; i>=0; i--)
    {
        maximo+=a[i];
        resp++;
        sum-=a[i];
        if(maximo>sum) break;
    }
    printf("%d", resp);
    return 0;
}
