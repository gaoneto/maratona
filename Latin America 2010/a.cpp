/*#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, double> > grafopeso[100001];
double d[100001];
int pi[100001], rota[100001], rota1[100001];

void dijkstra(int s)
{
    int u, v, i;
    d[s]=0;
    priority_queue<pair<double,int> > Q; 
    Q.push(make_pair<double,int>(-d[s],s)); 
    //-d[s] para trabalharmos com a fila de prioridades de mínimo 
    //iniciando com o vértice de origem
    while(!Q.empty())
    {      
        u=Q.top().second;
        Q.pop();
        for(i=0; i<grafopeso[u].size(); i++)
        {
            v=grafopeso[u][i].first;
            if(d[v]>d[u]+grafopeso[u][i].second)
            {
                d[v]=d[u]+grafopeso[u][i].second;
                pi[v]=u;
                Q.push(make_pair<double,int>(-d[v],v));
                //break;
            }
        }
    }
}

int main()
{
    int n, i, j, k, m, a, q, s, t, aux, flag;
    double l;
    while(scanf("%d", &n) && n)
    {
        for(i=0; i<n; i++)
        {
            d[i]=1000000000000000.0;
            pi[i]=-1;
        }
        for(i=1; i<=n-1; i++)
        {
            scanf("%d %lf", &a, &l);
            grafopeso[i].push_back(make_pair(a, l));
            grafopeso[a].push_back(make_pair(i, l));
        }    
        dijkstra(0);
        scanf("%d", &q);
        for(i=0; i<q; i++)
        {
            scanf("%d %d", &s, &t);
            j=k=flag=0;
            aux=s;
            while(aux!=0)
            {
                aux=pi[aux];
                j++;
            }
            aux=s;
            for(m=j-1; m>=0; m--)
            {
                aux=pi[aux];
                rota[m]=aux;
            }
            aux=t;
            while(aux!=0)
            {
                aux=pi[aux];
                k++;
            }
            aux=t;
            for(m=k-1; m>=0; m--)
            {
                aux=pi[aux];
                rota1[m]=aux;
            }
            rota[j++]=s;
            rota1[k++]=t;
            if(s==0 || t==0)
                printf("%.0lf ", d[max(s, t)]);
            else
            {
                 for(m=0; m<min(j, k); m++)
                     if(rota[m]!=rota1[m])
                     {
                         aux=rota1[m-1];
                         flag=1;
                         break;
                     }
                 if(!flag) printf("%.0lf ", d[max(s, t)]-d[min(s, t)]);
                 else printf("%.0lf ", d[s]+d[t]-2*d[aux]);
            }
        }
        for(i=0; i<n; i++)
            grafopeso[i].clear();
        printf("\n");
    }
    return 0;
}*/


//Solução utilizando LCA(Lowest Common Ancestor) em <O(nlog(n)), O(log)n))>
#include <stdio.h>
#include <iostream>

using namespace std;

double d[100001];
int pi[100001], level[100001], P[100001][20], n;

void process()
{
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; (1 << j)<n; j++)
            P[i][j]=-1;
    for(i=0; i<n; i++)
        P[i][0]=pi[i];
    for(j=1; (1 << j)<n; j++)
        for(i=0; i<n; i++)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}

int query(int p, int q)
{
    int tmp, log, i;
    if(level[p]<level[q])
    {
        tmp=p;
        p=q;
        q=tmp;
    }
    for(log=1; (1 << log)<=level[p]; log++);
    log--;
    for(i=log; i>=0; i--)
        if(level[p]-(1 << i)>=level[q])
            p=P[p][i];
    if(p==q) return p;
    for(i=log; i>=0; i--)
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
        {
            p=P[p][i];
            q=P[q][i];
        }
    return pi[p];
}

int main()
{
    int i, a, q, s, t, lca;
    double l;
    while(scanf("%d", &n) && n)
    {
        d[0]=0.0;
        pi[0]=-1;
        level[0]=0;
        for(i=1; i<=n-1; i++)
        {
            scanf("%d %lf", &a, &l);
            level[i]=level[a]+1;
            pi[i]=a;
            d[i]=d[a]+l;
        }    
        process();
        scanf("%d", &q);
        for(i=0; i<q; i++)
        {
            scanf("%d %d", &s, &t);
            lca=query(s, t);
            printf("%.0lf ", d[s]+d[t]-2*d[lca]);
        }
        printf("\n");
    }
    return 0;
}
