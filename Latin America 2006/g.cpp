#include <stdio.h>
#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

vector<int> grafo[10001];
int vis[10001], p[10001], c, resp;

void dfs(int v, int u)
{
    int i, w;
    vis[v]=1;
    for(i=0; i<grafo[v].size(); i++)
    {
        w=grafo[v][i];
        if(!vis[w]) dfs(w, v);
    }
    if(p[v]>=c) resp++;
    else p[u]+=p[v];
}

int main()
{
    int n, i, j, x[10001], y[10001], dist, ind, minimo;
    while(scanf("%d %d", &n, &c) && (n || c))
    {
        for(i=0; i<n; i++)
        {
            grafo[i].clear();
            vis[i]=0;
            scanf("%d %d %d", &x[i], &y[i], &p[i]);
            minimo=INF;
            for(j=0; j<i; j++)
            {
                dist=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
                if(dist<minimo)
                {
                    minimo=dist;
                    ind=j;
                }
            }
            if(minimo!=INF)
            {
                grafo[i].push_back(ind);
                grafo[ind].push_back(i);
            }
        }
        resp=0;
        dfs(0, 0);
        printf("%d\n", resp);
    }
    return 0;
}
