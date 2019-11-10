#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000
#define MATCH(k) (k+n+1)
#define TIME(k) (k+1)
#define SOURCE (0)
#define SINK (1)

int min(int a, int b)
{
    return ((a>=b) ? b : a);    
}

int grafo[800][800], vis[800], pi[800], n, m, g, aux, match;
vector<int> adj[800];

typedef struct {
    int pontos;
    int falta;
    int enf[40];
} equipe;

equipe times[40];

void dfs(int u)
{
    int i, v;
    vis[u]=1;
    if(vis[SINK]) return;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(grafo[u][v] && !vis[v])
        {
            pi[v]=u;
            dfs(v);
            if(vis[SINK]) return;
        }
        if(vis[SINK]) return;
    }
}

int ff(int s, int t)
{
    int i, aux, garg, fluxo=0;
    while(1)
    {
        for(i=0; i<=n+match; i++)
        {
            vis[i]=0;
            pi[i]=-1;
        }
        dfs(s);
        if(!vis[t]) break;
        garg=INF;
        for(aux=t; pi[aux]!=-1; aux=pi[aux])
            garg=min(garg, grafo[pi[aux]][aux]);
        for(aux=t; pi[aux]!=-1; aux=pi[aux])
        {
            grafo[aux][pi[aux]]+=garg;
            grafo[pi[aux]][aux]-=garg;
        }
        fluxo+=garg;
    }
    return fluxo;
}

int main()
{
    int i, j, t1, t2, fluxo, l, flag;
    char c;
    while(scanf("%d %d %d", &n, &m, &g) && (n || m || g))
    {
        match=n*(n-1)/2-(n-1);
        aux=l=flag=0;
        for(i=0; i<=n+match; i++)
            for(j=0; j<=n+match; j++)
                grafo[i][j]=0;
        for(i=0; i<n; i++)
        {
            times[i].falta=m*(n-1);
            times[i].pontos=0;
            for(j=0; j<n; j++)
                times[i].enf[j]=0;
            times[i].enf[i]=m;
        }
        for(i=0; i<g; i++)
        {
            scanf("%d %c %d", &t1, &c, &t2);
            times[t1].enf[t2]++;
            times[t2].enf[t1]++;
            times[t1].falta--;
            times[t2].falta--;
            if(c=='<') times[t2].pontos+=2;
            else
            {
                times[t1].pontos++;
                times[t2].pontos++;
            }
        }
        for(i=0; i<n; i++)
        {
            times[0].pontos+=2*(m-times[0].enf[i]);
            times[i].falta-=(m-times[0].enf[i]);
        }
        for(i=1; i<n; i++)
            if(times[i].pontos>=times[0].pontos)
            {
                flag=1;
                break;
            }
        if(flag) printf("N\n");
        else if(times[0].pontos==2*m*(n-1)) printf("Y\n");
        else
        {
            for(i=0; i<=n+match; i++) adj[i].clear();
            for(i=1; i<n; i++)
            {
                if(times[i].pontos+2*times[i].falta>=times[0].pontos) grafo[SOURCE][TIME(i)]=times[0].pontos-times[i].pontos-1;
                else grafo[SOURCE][TIME(i)]=2*times[i].falta;
                adj[SOURCE].push_back(TIME(i));
                adj[TIME(i)].push_back(SOURCE);
                for(j=i+1; j<n; j++)
                {
                    grafo[TIME(i)][MATCH(aux)]=2*(m-times[i].enf[j]);
                    grafo[TIME(j)][MATCH(aux)]=2*(m-times[i].enf[j]);
                    grafo[MATCH(aux)][SINK]=2*(m-times[i].enf[j]);
                    adj[TIME(i)].push_back(MATCH(aux));
                    adj[MATCH(aux)].push_back(TIME(i));
                    adj[TIME(j)].push_back(MATCH(aux));
                    adj[MATCH(aux)].push_back(TIME(j));
                    adj[MATCH(aux)].push_back(SINK);
                    adj[SINK].push_back(MATCH(aux));
                    aux++;
                    l+=(m-times[i].enf[j]);
                }
            }
            fluxo=ff(SOURCE, SINK);
            if(2*l==fluxo) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
