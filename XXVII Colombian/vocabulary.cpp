#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

vector<int> adj[1111];
int match[1111], d[1111], n;

int bfs()
{
    int u, v, i;
    queue<int> q;
    for(i=0; i<=n; i++)
    {
        if(!match[i])
        {
            d[i]=0;
            q.push(i);
        }
        else d[i]=INF;
    }
    d[0]=INF;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u)
        {
            for(i=0; i<adj[u].size(); i++)
            {
                v=adj[u][i];
                if(d[match[v]]==INF)
                {
                    d[match[v]]=d[u]+1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (d[0]!=INF);
}

int dfs(int u)
{
    int i, v;
    if(u)
    {
        for(i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            if(d[match[v]]==d[u]+1 && dfs(match[v]))
            {
                match[v]=u;
                match[u]=v;
                return 1;
            }
        }
        d[u]=INF;
        return 0;
    }
    return 1;
}

int hopcroft_karp()
{
    int matching=0, i;
    while(bfs()) for(i=1; i<=n; i++) if(!match[i] && dfs(i)) matching++;
    return matching;
}

int main()
{
    int c, v, fv[555][27], fc[555][27], i, j, k, sv[555], sc[555];
    char s[111];
    while(scanf("%d %d", &v, &c)!=EOF)
    {
        n=v+c;
        for(i=0; i<v; i++) for(j=0; j<27; j++) fv[i][j]=0;
        for(i=0; i<c; i++) for(j=0; j<27; j++) fc[i][j]=0;
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            match[i]=0;
            d[i]=INF;
        }
        for(i=0; i<v; i++)
        {
            scanf("%s", s);
            sv[i]=strlen(s);
            for(j=0; j<sv[i]; j++) fv[i][s[j]-'a']++;
        }
        for(i=0; i<c; i++)
        {
            scanf("%s", s);
            sc[i]=strlen(s);
            for(j=0; j<sc[i]; j++) fc[i][s[j]-'a']++;
        }
        for(i=0; i<v; i++) for(j=0; j<c; j++)
        {
            for(k=0; k<27; k++) if(fv[i][k]<fc[j][k]) break;
            if(k==27) adj[i+1].push_back(v+j+1);
        }
        printf("%d\n", hopcroft_karp());
    }
    return 0;
}
