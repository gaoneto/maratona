#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > ans;
vector<pair<int, int> > adj[2222];
int pi[2222], rank[2222], vis[2222], d[2222][2222], a[2222][2222];

void dfs(int u, int id)
{
    int i, v, w;
    vis[u]=1;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i].first;
        w=adj[u][i].second;
        if(!vis[v])
        {
            d[id][v]=d[id][u]+w;
            dfs(v, id);
        }
    }
}

int FindSet(int x)
{
    if(pi[x]!=x) return pi[x]=FindSet(pi[x]);
    return x;
}

void Union(int x, int y, int v)
{
    int X=FindSet(x);
    int Y=FindSet(y);
    if(X==Y) return;
    ans.push_back(make_pair(x, make_pair(y, v)));
    adj[x].push_back(make_pair(y, v));
    adj[y].push_back(make_pair(x, v));
    if(rank[X]>rank[Y]) pi[Y]=X;
    else
    {
        pi[X]=Y;
        if(rank[X]==rank[Y]) rank[Y]++;
    }
}

int main()
{
    int i, j, n, f=0;
    while(scanf("%d", &n)!=EOF)
    {
        if(f) printf("\n");
        f=1;
        priority_queue<pair<int, pair<int, int> > > q;
        ans.clear();
        for(i=1; i<=n; i++) pi[i]=i, rank[i]=0, adj[i].clear();
        for(i=1; i<=n; i++) for(j=1; j<=n; j++)
        {
            scanf("%d", &a[i][j]);
            if(i<j) q.push(make_pair(-a[i][j], make_pair(i, j)));
        }
        while(!q.empty())
        {
            int a, b, c;
            c=-q.top().first;
            a=q.top().second.first;
            b=q.top().second.second;
            q.pop();
            Union(a, b, c);
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++) vis[j]=0;
            dfs(i, i);
        }
        if(n==2)
        {
            printf("1 2 %d\n", a[1][2]);
            printf("2 1 %d\n", a[1][2]);
        }
        else
        {
            vector<pair<int, int> > v;
            for(i=1; i<=n; i++) for(j=1; j<=n; j++) if(d[i][j]!=a[i][j]) v.push_back(make_pair(i, j));
            for(i=0; i<v.size(); i++)
            {
                int x, y, c;
                x=v[i].first;
                y=v[i].second;
                c=a[x][y];
                for(j=0; j<v.size(); j++)
                {
                    int xx=v[j].first, yy=v[j].second;
                    int d1=d[x][xx]+c+d[y][yy];
                    int d2=d[x][yy]+c+d[y][xx];
                    if(min(d1, d2)<a[xx][yy]) break;
                    if(d1!=a[xx][yy] && d2!=a[xx][yy]) break;
                }
                if(j==(int)v.size())
                {
                    ans.push_back(make_pair(x, make_pair(y, c)));
                    break;
                }
            }
            if((int)ans.size()==n-1) ans.push_back(ans[0]);
            for(i=0; i<ans.size(); i++) printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
        }
    }
    return 0;
}
