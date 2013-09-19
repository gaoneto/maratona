#include <cstdio>

int main()
{
    int i, j, n, ans;
    while(scanf("%d %d %d", &n, &i, &j)!=EOF)
    {
        ans=0;
        i+=(1<<n)-1;
        j+=(1<<n)-1;
        while(i!=j)
        {
            i/=2;
            j/=2;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
