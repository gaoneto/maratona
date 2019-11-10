#include <stdio.h>

int mao[2][14], maximo, n;

void comum(int trinca, int v, int u)
{
    int i, j, k;
    if(trinca>maximo) maximo=trinca;
    for(i=u; i<13; i++)
    {
        if(mao[v][i])
        {
            for(j=i; j<14; j++)
            {
                if(i==j && mao[v][i]==1) continue;
                if(mao[v][j])
                {
                    for(k=j; k<14; k++)
                        if(i!=k && i+j>k && mao[v][k])
                            if((i==j && mao[v][i]==2 && mao[v][k]) || (j==k && mao[v][j]==2 && mao[v][i]) || (i!=j && j!=k && mao[v][i] && mao[v][j] && mao[v][k]))
                            {
                                mao[v][i]--;
                                mao[v][j]--;
                                mao[v][k]--;
                                comum(trinca+1, v, i);
                                mao[v][i]++;
                                mao[v][j]++;
                                mao[v][k]++;
                            }
                }
            }
        }
    }
}

int main()
{
    int x, i, j, k, perf[2], com[2];
    while(scanf("%d", &n) && n)
    {
        for(i=0; i<14; i++)
            mao[0][i]=mao[1][i]=0;
        perf[0]=perf[1]=com[0]=com[1]=0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &x);
            if(i%2==0) mao[0][x]++;
            else mao[1][x]++;
        }
        for(i=1; i<14; i++)
        {
            perf[0]+=mao[0][i]/3;
            mao[0][i]%=3;
            perf[1]+=mao[1][i]/3;
            mao[1][i]%=3;
        }
        if(perf[0]!=perf[1])
        {
            if(perf[0]>perf[1]) printf("1\n");
            else printf("2\n");
        }
        else
        {
            maximo=0;
            comum(0, 0, 1);
            com[0]=maximo;
            maximo=0;
            comum(0, 1, 1);
            com[1]=maximo;
            if(com[0]!=com[1])
            {
                if(com[0]>com[1]) printf("1\n");
                else printf("2\n");
            }
            else printf("0\n");
        }
    }
    return 0;    
}
