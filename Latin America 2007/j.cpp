#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
#define INF 1000000000

using namespace std;
    
int H, R, g, flag, total, vis[50000], liga[50000], cont;
vector<int> grafo[50000];
vector<pair<int, int> > rel;

void dfs(int v)
{
    int i;
    vis[v] = 1; total += grafo[v].size();
    for(i=0;i<grafo[v].size();i++) if(!vis[grafo[v][i]]) dfs(grafo[v][i]);
}

int main()
{
    int a, b, i, j;
    while(scanf("%d%d", &H, &R) && H)
    {
        total=0; flag=1;
        for(i=0;i<H;i++)
        {
            grafo[i].clear();
            vis[i] = liga[i] = 0;
        }
        rel.clear();
        for(i=0;i<R;i++)
        {
            scanf("%d%d", &a, &b);
            a--; b--;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
            rel.push_back(make_pair(a, b));
        }
        for(i=0;i<H;i++) if(!grafo[i].empty()) break;
        total = 0;
        dfs(i);
        if(total != 2*R)
        {
            printf("N\n");
            continue;
        }
        g=INF;
        for(i=0;i<R;i++) g = min(g, max((int)grafo[rel[i].first].size(), (int)grafo[rel[i].second].size()));
        total = 0;
        for(i=0;i<H;i++)
        {
  	    if(grafo[i].size()<g) continue;
            liga[i] = 1;
            total++;
            cont = 0;
            for(j=0;j<grafo[i].size();j++) if(liga[grafo[i][j]]) cont++;
            if(cont != total-1)
            {
                flag = 0;
                break;
            }
        }
        if(flag) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
