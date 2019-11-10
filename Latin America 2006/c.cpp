#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <string.h>
#include <string>
#define MMAX 36
#define INF 100000

using namespace std;

int n, m, maximo[6], minimo[MMAX], tem[MMAX];
vector<string> v[MMAX], mus, art;
set<string> cand, s[MMAX];

int golden_sum(int u)
{
    int i, j, k, ret=0, used[6], size;
    cand.clear();
    for(i=0; i<m; i++)
    {
        maximo[i]=0;
        if(u & (1 << i)) used[i]=1;
        else used[i]=0;
    }
    for(i=0; i<n+m; i++)  
    {
        minimo[i]=INF;     
        if(i>=n && !used[i-n]) continue;
        size=v[i].size();
        for(j=0; j<size; j++)
        {
            if(cand.count(v[i][j])) continue;
            cand.insert(v[i][j]);
            for(k=0; k<n+m; k++)
            {
                if(k>=n && !used[k-n]) continue;
                if(k!=i && s[k].count(v[i][j])) break;
            }
            if(k==n+m)
            {
                minimo[i]=v[i][j].length();
                break;
            }
        }
        if(i<n) maximo[tem[i]]=max(maximo[tem[i]], minimo[i]);
        if(minimo[i]==INF && !used[tem[i]]) return INF;
    }
    for(i=0; i<n+m; i++)
    {
        if(i>=n && !used[i-n]) continue;
        ret+=minimo[i];
    }
    for(i=0; i<m; i++) if(u & (1 << i)) ret-=maximo[i];
    return ret;
}

int main()
{
    int i, j, k, smus, resp, cont, sart;
    char musica[MMAX], artista[MMAX];
    string s1;
    while(scanf("%d", &n) && n)
    {
        mus.clear();
        art.clear();
        for(i=0; i<n; i++)
        {
            v[i].clear();
            s[i].clear();
            scanf("%s %s", musica, artista);
            mus.push_back(musica);
            smus=strlen(musica);
            for(j=0; j<smus; j++)
                for(k=0; k+j<smus; k++)
                {
                    s1=mus[i].substr(k, 1+j);
                    v[i].push_back(s1);
                    s[i].insert(s1);
                }
            for(j=0; j<art.size(); j++) if(art[j]==(string)artista) break;
            if(j==art.size()) art.push_back(artista);
            tem[i]=j;
        }
        m=art.size();
        for(i=0; i<m; i++)
        {
            v[n+i].clear();
            s[n+i].clear();
            mus.push_back(art[i]);
            sart=art[i].length();
            for(j=0; j<sart; j++)
                for(k=0; k+j<sart; k++)
                {
                    s1=mus[n+i].substr(k, 1+j);
                    v[n+i].push_back(s1);
                    s[n+i].insert(s1);
                }
        }
        resp=INF;
        for(i=0; i<(1 << m);i++)
        {
            resp=min(resp, golden_sum(i));
            if(resp==n) break;
        }
        printf("%d\n", resp);
    }
    return 0;
}
