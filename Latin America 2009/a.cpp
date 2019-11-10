#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

vector<int> grafo[100010];
int m[100010], vis[100010], d[100010], ordem[100010], aux[100010], n;
queue<int> Q;

bool compara(int a, int b)
{
    return (d[a]<d[b]);
}

void bfs(int s)
{
    int u, v, i;
    for(i=0; i<n+1; i++)
    {
        vis[i]=0;
        d[i]=INF;
        ordem[i]=i;
    }
    vis[s]=1;
    Q.push(s); 
    d[s]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0; i<grafo[u].size(); i++)
        {
            v=grafo[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                d[v]=d[u]+1;
                Q.push(v);
            }
        }
    }
}

int bb(int n, int x)
{
    int l, r, m;
    l=0; r=n-1;
    while(l<r)
    {
        m=(l+r)/2;
        if(d[ordem[m]]<x) l=m+1;
        else r=m;
    }
    if(d[ordem[r]]<x) return r+1;
    return r;
}

int main()
{
    int i, j, b, ind, cont, a;
    double num, t;
    while(scanf("%d %lf", &n, &t) && (n || t))
    {
        for(i=0; i<n+1; i++) grafo[i].clear();
        for(i=0; i<n; i++)
        {
            scanf("%d", &b);
            grafo[b].push_back(i+1);
            m[i]=0;
        }
        bfs(0);
        for(i=0; i<n+1; i++)
            if(grafo[i].size()==0)
            {
                d[i]=INF;
                m[i]=1;
            }
        stable_sort(ordem, ordem+n+1, compara);
        ind=bb(n+1, INF);
        for(i=ind-1; i>=0; i--)
        {
            cont=0;
            a=grafo[ordem[i]].size();
            for(j=0; j<a; j++)
            {
                aux[cont++]=m[grafo[ordem[i]][j]];
            }
            sort(aux, aux+cont);
            num=ceil(t*cont/100);
            a=(int)num;
            for(j=0; j<a; j++) m[ordem[i]]+=aux[j];
        }
        printf("%d\n", m[0]);
    }
    return 0;
}
