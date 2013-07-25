#include <stdio.h>
#include <iostream>
#include <queue>
#include <utility>
#define INF 1000000000

using namespace std;

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int r, c, vis[1010][1010], grid[1010][1010], d[1010][1010], dist;
char g[1010];
queue<pair<int, int> > q;

void bfs(int s, int t)
{
    int i, u, v;
    vis[s][t]=1;
    d[s][t]=0;
    q.push(make_pair(s, t));
    while(!q.empty())
    {
        u=q.front().first;
        v=q.front().second;
        q.pop();
        for(i=0; i<4; i++) if(u+dx[i]>=0 && u+dx[i]<r && v+dy[i]>=0 && v+dy[i]<c && !vis[u+dx[i]][v+dy[i]] && grid[u+dx[i]][v+dy[i]]!=-1)
        {
            vis[u+dx[i]][v+dy[i]]=1;
            d[u+dx[i]][v+dy[i]]=d[u][v]+1;
            q.push(make_pair(u+dx[i], v+dy[i]));
        }
    }
}

int main()
{
    int t, i, j, si, sj, ei, ej, resp=0;
    scanf("%d %d", &r, &c);
    for(i=0; i<r; i++)
    {
        scanf("%s", g);
        for(j=0; j<c; j++)
        {
            d[i][j]=INF;
            if(g[j]=='T') grid[i][j]=-1, vis[i][j]=1;
            else if(g[j]=='S') si=i, sj=j;
            else if(g[j]=='E') ei=i, ej=j;
            else grid[i][j]=g[j]-'0';
        }
    }
    bfs(si, sj);
    dist=d[ei][ej];
    for(i=0; i<r; i++) for(j=0; j<c; j++)
    {
        vis[i][j]=0;
        d[i][j]=INF;
    }
    bfs(ei, ej);
    for(i=0; i<r; i++) for(j=0; j<c; j++) if(d[i][j]<=dist && grid[i][j]>0) resp+=grid[i][j];
    printf("%d", resp);
    return 0;    
}
