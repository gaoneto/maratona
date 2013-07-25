#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>
#define INF 1000000000

using namespace std;

int n, d[110], D, a[110], vis[110];
vector<pair<int, int> > grafo[110];

void dijkstra(int s)
{
    int u, v, i;
    d[s]=0;
    priority_queue<pair<int, int> > Q;
    Q.push(make_pair(-d[s], s));
    while(!Q.empty())
    {
        u=Q.top().second;
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(i=0; i<grafo[u].size(); i++)
        {
            v=grafo[u][i].first;
            if(d[v]>d[u]+grafo[u][i].second-a[u])
            {
                d[v]=d[u]+grafo[u][i].second-a[u];
                Q.push(make_pair(-d[v], v));
            }
        }
    }
}

int mod(int a) { return (a>0) ? a : -a; }

int main()
{
    int i, x[110], y[110], j;
    scanf("%d %d", &n, &D);
    for(i=1; i<n-1; i++) scanf("%d", &a[i]);
    a[0]=a[n-1]=0;
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        vis[i]=0;
        d[i]=INF;
    }
    for(i=0; i<n; i++) for(j=i+1; j<n; j++)
    {
        grafo[i].push_back(make_pair(j, D*(mod(x[i]-x[j])+mod(y[i]-y[j]))));
        grafo[j].push_back(make_pair(i, D*(mod(x[i]-x[j])+mod(y[i]-y[j]))));
    }
    dijkstra(0);
    printf("%d", d[n-1]);
    return 0;
}
