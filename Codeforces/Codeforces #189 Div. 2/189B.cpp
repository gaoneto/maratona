#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>
#define INF 1000000000
#define EPS 1e-8

using namespace std;

typedef long long ll;

vector<int> l, r, grafo[200];
int vis[200];

int bfs(int s, int t)
{
    int i, u, v;
    queue<int> q;
    vis[s]=1;
    if(vis[t]) return 1;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<grafo[u].size(); i++)
        {
            v=grafo[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                if(vis[t]) return 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    int i, n, a, b, t, j;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d", &t, &a, &b);
        if(t==1)
        {
            for(j=0; j<l.size(); j++)
            {
                if((a>l[j] && a<r[j]) || (b>l[j] && b<r[j])) grafo[(int)l.size()].push_back(j);
                if((l[j]>a && l[j]<b) || (r[j]>a && r[j]<b)) grafo[j].push_back((int)l.size());
            }
            l.push_back(a);
            r.push_back(b);
        }
        else
        {
            memset(vis, 0, sizeof(vis));
            a--, b--;
            printf("%s\n", bfs(a, b) ? "YES" : "NO");
        }
    }
    return 0;
}
