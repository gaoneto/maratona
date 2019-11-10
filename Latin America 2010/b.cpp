#include <stdio.h>

int mod(int a)
{
    if(a>=0) return a;
    else return -a;    
}

int main()
{
    int n, b, i, j, num[100], bola[100], aux, cont;
    while(scanf("%d %d", &n, &b)==2 && (n || b))
    {
        cont=0;
        memset(num, 0, sizeof(num));
        for(i=0; i<b; i++)
            scanf("%d", &bola[i]);
        for(i=0; i<b; i++)    
            for(j=0; j<b; j++)
            {
                aux=mod(bola[i]-bola[j]);
                num[aux]++;
            }
        for(i=0; i<=n; i++)
            if(num[i]==0)
            {
                cont++;
                break;
            }
        if(cont==0) printf("Y\n");
        else printf("N\n");
    }    
    return 0;
}
