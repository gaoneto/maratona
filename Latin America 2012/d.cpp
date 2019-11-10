#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, m, resp, j, aux, dig[10];
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        resp=0;
        for(i=n; i<=m; i++)
        {
            aux=i;
            memset(dig, 0, sizeof(dig));
            while(aux)
            {
                dig[aux%10]++;
                aux/=10;
            }
            for(j=0; j<10; j++) if(dig[j]>1) break;
            if(j==10) resp++;
        }
        printf("%d\n", resp);
    }
    return 0;
}
