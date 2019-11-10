#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

struct Trie {
    int g[100100][26];
    int estados;
    Trie() { init(); } 
    void init() 
    {
        int i;
        for(i=0; i<26; i++) g[0][i]=-1;
        estados=1;
    }
    void add(string s) 
    {
        int e=0, i=0, j, next=s[i]-'a';
        while(s[i]!='\0')
        {
            next=(s[i]-'a');
            if(g[e][next]==-1)
            {
                g[e][next]=estados;
                for(j=0; j<26; j++) g[estados][j]=-1;
                estados++;
            }
            e=g[e][next];
            i++;
        }
    }
};

Trie prefix, suffix;
int totsuffix, suf[26];
long long resp;

void dfssuffix(int u, int h)
{
    int i;
    for(i=0; i<26; i++)
        if(suffix.g[u][i]!=-1)
        {
            if(h) suf[i]++;
            dfssuffix(suffix.g[u][i], h+1);
        }
}

void dfsprefix(int u, int h)
{
    int i;
    if(h) resp+=totsuffix;
    for(i=0; i<26; i++)
        if(prefix.g[u][i]!=-1)
        {
            if(h) resp-=suf[i];
            dfsprefix(prefix.g[u][i], h+1);
        }
}

int main()
{
    char pal[1010];
    int i, p, s, size;
    while(scanf("%d %d", &p, &s) && (p || s))
    {
        prefix.init();
        suffix.init();
        memset(suf, 0, sizeof(suf));
        for(i=0; i<p; i++)
        {
            scanf("%s", pal);
            prefix.add((string)pal);
        }
        for(i=0; i<s; i++)
        {
            scanf("%s", pal);
            size=strlen(pal);
            reverse(pal, pal+size);
            suffix.add((string)pal);
        }
        totsuffix=suffix.estados-1;
        dfssuffix(0, 0);
        resp=0;
        dfsprefix(0, 0);
        printf("%lld\n", resp);
    }
    return 0;
}
