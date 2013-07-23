#include <stdio.h>
#include <string.h>
#define SOURCE 0
#define SINK 1
#define CATLOVER(k) k+2
#define DOGLOVER(k) k+cl+2

int grafo[550][550], vis[550], pi[550], v;

void dfs(int u)
{
    int i;
    vis[u]=1;
    for(i=0; i<v+2; i++) if(grafo[u][i] && !vis[i])
    {
        pi[i]=u;
        dfs(i);
    }
}

int ff(int s, int t)
{
    int i, aux, fluxo=0;
    while(1)
    {
        for(i=0; i<v+2; i++)
        {
            vis[i]=0;
            pi[i]=-1;
        }
        dfs(s);
        if(!vis[t]) break;
        for(aux=t; pi[aux]!=-1; aux=pi[aux])
        {
            grafo[aux][pi[aux]]++;
            grafo[pi[aux]][aux]--;
        }
        fluxo++;
    }
    return fluxo;
}

int main()
{
    int t, i, j, k, c, d, cl, dl, dogl[550], dogh[550], catl[550], cath[550], x, sizel, sizeh;
    char l[10], h[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &c, &d, &v);
        cl=dl=0;
        memset(grafo, 0, sizeof(grafo));
        for(i=0; i<v; i++)
        {
            scanf("%s %s", l, h);
            sizeh=strlen(h);
            sizel=strlen(l);
            if(l[0]=='C')
            {
                for(j=sizel-1, x=0, k=1; l[j]!='C'; j--, k*=10) x+=(l[j]-'0')*k;
                catl[cl]=x;
                for(j=sizeh-1, x=0, k=1; h[j]!='D'; j--, k*=10) x+=(h[j]-'0')*k;
                dogh[cl++]=x;
            }
            else
            {
                for(j=sizel-1, x=0, k=1; l[j]!='D'; j--, k*=10) x+=(l[j]-'0')*k;
                dogl[dl]=x;
                for(j=sizeh-1, x=0, k=1; h[j]!='C'; j--, k*=10) x+=(h[j]-'0')*k;
                cath[dl++]=x;
            }
        }
        for(i=0; i<cl; i++) for(j=0; j<dl; j++) if(catl[i]==cath[j] || dogh[i]==dogl[j]) grafo[CATLOVER(i)][DOGLOVER(j)]=1;
        for(i=0; i<cl; i++) grafo[SOURCE][CATLOVER(i)]=1;
        for(i=0; i<dl; i++) grafo[DOGLOVER(i)][SINK]=1;
        printf("%d\n", v-ff(SOURCE, SINK));
    }
    return 0;    
}
