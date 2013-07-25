#include <cstdio>
#include <string.h>

int r[110], c[110];

int main()
{
    int i, j, sr=0, sc=0, n;
    char s[250][250];
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%s", s[i]);
        for(j=1; j<=n; j++) if(s[i][j-1]=='.') r[i]=j;
    }
    for(j=1; j<=n; j++) for(i=1; i<=n; i++) if(s[i][j-1]=='.') c[j]=i;
    for(i=1; i<=n; i++)
    {
        if(r[i]) sr++;
        if(c[i]) sc++;
    }
    if(sr!=n && sc!=n) printf("-1");
    else
    {
        if(sr==n) for(i=1; i<=n; i++) printf("%d %d\n", i, r[i]);
        else for(i=1; i<=n; i++) printf("%d %d\n", c[i], i);
    }
    return 0;    
}
