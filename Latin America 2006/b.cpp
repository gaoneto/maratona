#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#define INF 1000000000
#define MAX 1001

using namespace std;

bool alagado[MAX][MAX];
int d[MAX][MAX], r, c, xf, yf;
int dx[8]={-1, 1, 1, -1, -1, 0, 1, 0};
int dy[8]={1, 1, -1, -1, 0, 1, 0, -1};
int pseco[8]={3, 3, 3, 3, 2, 2, 2, 2};
int palag[8]={4, 4, 4, 4, 3, 3, 3, 3};

int mod(int a)
{
    return ((a>0) ? a : -a);
}

void dijkstra(int x, int y)
{
    priority_queue<pair<int, pair<int, int> > > Q;
    int u, v, i, h;
    d[x][y]=0;
    Q.push(make_pair(-d[x][y], make_pair(x, y)));
    while(!Q.empty()) 
    {
        u=Q.top().second.first;
        v=Q.top().second.second;
        Q.pop();
        if(u==xf && v==yf) return;
        for(i=0; i<8; i++)
            if(u+dx[i]>=0 && u+dx[i]<r && v+dy[i]>=0 && v+dy[i]<c)
            {
                if(alagado[u][v])
                {
                    if(!alagado[u+dx[i]][v+dy[i]] && d[u+dx[i]][v+dy[i]]>d[u][v]+palag[i])
                    {
                        d[u+dx[i]][v+dy[i]]=d[u][v]+palag[i];
                        h=3*min(mod(u+dx[i]-xf), mod(v+dy[i]-yf))+2*mod(mod(u+dx[i]-xf)-mod(v+dy[i]-yf));
                        Q.push(make_pair(-(d[u+dx[i]][v+dy[i]]+h), make_pair(u+dx[i], v+dy[i])));
                    }
                }
                else
                {
                    if(d[u+dx[i]][v+dy[i]]>d[u][v]+pseco[i])
                    {
                        d[u+dx[i]][v+dy[i]]=d[u][v]+pseco[i];
                        h=3*min(mod(u+dx[i]-xf), mod(v+dy[i]-yf))+2*mod(mod(u+dx[i]-xf)-mod(v+dy[i]-yf));
                        Q.push(make_pair(-(d[u+dx[i]][v+dy[i]]+h), make_pair(u+dx[i], v+dy[i])));
                    }
                }
            }
    }
}

int main()
{
    int W, xi, yi, x1, x2, y1, y2, i, j, k;
    while(scanf("%d %d", &r, &c) && (r || c))
    {
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                alagado[i][j]=false;
                d[i][j]=INF;
            }
        scanf("%d %d %d %d %d", &xi, &yi, &xf, &yf, &W);
        xi--; yi--; xf--; yf--;
        for(i=0; i<W; i++)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1--; x2--; y1--; y2--;
            for(j=x1; j<=x2; j++)
                for(k=y1; k<=y2; k++)
                    alagado[j][k]=true;
        }
        dijkstra(xi, yi);
        if(d[xf][yf]==INF) printf("impossible\n");
        else printf("%d\n", d[xf][yf]);
    }
    return 0;
}
