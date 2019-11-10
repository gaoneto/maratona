#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>
#define INF 1000000000

using namespace std;

int grafo[500][500], d[500], vis[500], n, s;
vector<int> pi[500];

void dijkstra(int s)
{
    int u, i;
    d[s]=0;
    priority_queue<pair<int,int> > Q; 
    Q.push(make_pair<int,int>(-d[s],s)); 
    while(!Q.empty())
    {      
        u=Q.top().second;
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(i=0; i<n; i++)
            if(grafo[u][i]!=0)
            {
                if(d[i]>d[u]+grafo[u][i])
                {
                    d[i]=d[u]+grafo[u][i];
                    pi[i].clear();
                    pi[i].push_back(u);
                    Q.push(make_pair<int,int>(-d[i],i));
                }
                else if(d[i]==d[u]+grafo[u][i]) pi[i].push_back(u);
            }
    }
}

void apaga(int v)
{
    int i;
    for(i=0; i<pi[v].size(); i++)
    {
        grafo[pi[v][i]][v]=0;
        if(pi[v][i]!=s) apaga(pi[v][i]);
    }    
}

int main()
{
    int m, u, v, p, i, j, dest;
    while(scanf("%d %d", &n, &m)==2 && (n || m))
    {
        scanf("%d %d", &s, &dest);
        for(i=0; i<n; i++)
        {
            d[i]=INF;
            pi[i].clear();
            vis[i]=0;
            for(j=0; j<n; j++) grafo[i][j]=0;         
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &p);
            grafo[u][v]=p;
        }
        dijkstra(s);
        apaga(dest);
        for(i=0; i<n; i++)
        {
            d[i]=INF;
            vis[i]=0;
        }         
        dijkstra(s);
        if(d[dest]==INF) printf("-1\n");
        else printf("%d\n", d[dest]);
    }
    return 0;
}
