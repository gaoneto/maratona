#include <stdio.h>

int max(int a, int b)
{
    return ((a>=b) ? a : b);    
}

int main()
{
    int m, n, i, j, maximo, linha[100000], soma[100000];
    while(scanf("%d %d", &m, &n) && (m || n))
    {
        int doces[m][n];
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d", &doces[i][j]);
        for(i=0; i<m; i++)
        {
            soma[0]=doces[i][0];
            if(n>1) soma[1]=doces[i][1];
            if(n>2) soma[2]=max(doces[i][0]+doces[i][2], doces[i][1]);
            for(j=3; j<n; j++)
                soma[j]=doces[i][j]+max(soma[j-2], soma[j-3]);
            if(n==1) linha[i]=soma[0];
            else linha[i]=max(soma[n-1], soma[n-2]);
        }
        soma[0]=linha[0];
        if(m>1) soma[1]=linha[1];
        if(m>2) soma[2]=max(linha[0]+linha[2], linha[1]);
        for(i=3; i<m; i++)
            soma[i]=linha[i]+max(soma[i-2], soma[i-3]);
        if(m==1) maximo=soma[0];
        else maximo=max(soma[m-1], soma[m-2]);
        printf("%d\n", maximo);
    }
    return 0;    
}
