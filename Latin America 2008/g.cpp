#include <stdio.h>

int main()
{
    int n, c, p, i, aux, pos[2000], carro[2000];
    while(scanf("%d", &n)==1 && n)
    {
        aux=0;
        for(i=1; i<=n; i++)
        {
            pos[i]=0;
            carro[i]=0;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d %d", &c, &p);
            if(p>=-1000 && p<=1000)
            {
                pos[i]=i+p;
                if(pos[i]>0) 
                    carro[pos[i]]=c;
            }
        }
        for(i=1; i<=n; i++)
            if(carro[i]==0)
            {
                aux++;
                break;
            }
        if(aux==0)
        {
            for(i=1; i<=n; i++)
                printf("%d ", carro[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;    
}
