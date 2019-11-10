#include <stdio.h>

int dx[6]={-1, -1, 0, 1, 1, 0};
int dy[6]={0, 1, 1, 0, -1, -1};
int r, c, vis[105][105], vis1[105][105];
char galou[105][105], res[105][105];

void dfs_visit(int u, int v)
{
    int i, j;
    if(res[u][v]=='B') return;
    for(i=0; i<6; i++)
        if(u+dx[i]>=0 && u+dx[i]<r && v+dy[i]>=0 && v+dy[i]<c)
        {
            if(res[u+dx[i]][v+dy[i]]=='B') return;
            if(vis[u][v]==vis[u+dx[i]][v+dy[i]])
            {
                res[u+dx[i]][v+dy[i]]='B';
                return;
            }
            if(galou[u+dx[i]][v+dy[i]]!='.' && !vis[u+dx[i]][v+dy[i]])
            {
                if(galou[u+dx[i]][v+dy[i]]=='I' && vis[u][v]==1)
                {
                    res[u+dx[i]][v+dy[i]]='B';
                    return;
                }
                if(vis[u][v]==1)
                {
                    res[u+dx[i]][v+dy[i]]=')';
                    vis[u+dx[i]][v+dy[i]]=2;
                    dfs_visit(u+dx[i], v+dy[i]);
                }
                else
                {
                    res[u+dx[i]][v+dy[i]]='(';
                    vis[u+dx[i]][v+dy[i]]=1;
                    dfs_visit(u+dx[i], v+dy[i]);
                }
            }
        }
}

void dfs()
{
    int i, j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            if(!vis[i][j] && galou[i][j]=='I')
            {
                res[i][j]='(';
                vis[i][j]=1;
                dfs_visit(i, j);
            }
}

void dfs_visit1(int u, int v)
{
    int i, j;
    vis1[u][v]=1;
    res[u][v]='B';
    for(i=0; i<6; i++)
        if(u+dx[i]>=0 && u+dx[i]<r && v+dy[i]>=0 && v+dy[i]<c && !vis1[u+dx[i]][v+dy[i]] && res[u+dx[i]][v+dy[i]]!='.')
            dfs_visit1(u+dx[i], v+dy[i]);
}

void dfs1()
{
    int i, j;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            if(!vis1[i][j] && res[i][j]=='B')
                dfs_visit1(i, j);
}

int main()
{
    int i, j;
    while(scanf("%d %d", &r, &c) && (r || c))
    {
        for(i=0; i<r; i++)
        {
            scanf("%s", galou[i]);
            for(j=0; j<c; j++)
            {
                if(galou[i][j]=='.') res[i][j]='.';
                else res[i][j]='F';
                vis1[i][j]=vis[i][j]=0;
            }
        }
        dfs();
        dfs1();
        printf("\n");
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
                printf("%c", res[i][j]);
            printf("\n");
        }
    }
    return 0;    
}
