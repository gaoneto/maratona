#include <stdio.h>

int max[110];
char suc[110];

int main()
{
    int i, j, n, m, resp=0;
    char g[110][110];
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    {
        scanf("%s", g[i]);
        for(j=0; j<m; j++) if((g[i][j]-'0')>max[j]) max[j]=g[i][j]-'0';
    }
    for(i=0; i<n; i++) for(j=0; j<m; j++) if(g[i][j]-'0'==max[j]) suc[i]=1;
    for(i=0; i<n; i++) if(suc[i]) resp++;
    printf("%d", resp);
    return 0;
}
