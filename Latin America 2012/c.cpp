#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int g[1000001][27][2];
int estados;
int resp;

void init() 
{
    int i;
    for(i=0; i<27; i++)
    {
        g[0][i][0]=-1;
        g[0][i][1]=0;
    }
    estados=1;
}

void add(string s) 
{
    int e=0, i=0, j, next;
    while(s[i]!='\0')
    {
        next=(s[i]-'a');
        if(g[e][next][0]==-1)
        {
            g[e][next][0]=estados;
            g[e][next][1]=1;
            for(j=0; j<27; j++)
            {
                g[estados][j][0]=-1;
                g[estados][j][1]=0;
            }
            estados++;
        }
        else g[e][next][1]++;
        e=g[e][next][0];
        if(s[i+1]=='\0') g[e][26][0]=1;
        i++;
    }
}

void dfs(int u)
{
    int i, cont=0, letras=0;
    for(i=0; i<26; i++) if(g[u][i][0]!=-1)
    {
        cont++;
        letras+=g[u][i][1];
    }
    if(cont>1 && u) resp+=letras;
    if(cont==1 && g[u][26][0]==1) resp+=letras;
    for(i=0; i<26; i++) if(g[u][i][0]!=-1 && letras>1) dfs(g[u][i][0]);
}

int main()
{
    char pal[100];
    int i, n;
    while(scanf("%d", &n)!=EOF)
    {
        init();
        for(i=0; i<n; i++)
        {
            scanf("%s", pal);
            add((string)pal);
        }
        resp=n;
        dfs(0);
        printf("%.2lf\n", (double)resp/n);
    }
    return 0;
}
