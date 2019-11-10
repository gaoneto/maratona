#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#define INF 1000000000

using namespace std;

vector<pair<pair<int, int>, pair<int, int> > > placar;
pair<pair<int, int>, pair<int, int> > aux;

int main()
{
    int i, j, k, m, n, t, p, size, tempo, erros, questoes, tmax, tmin, t1, t2;
    char desc[10];
    while(scanf("%d %d", &t, &p) && (t || p))
    {
        tmax=t1=INF;
        tmin=t2=1;
        for(i=0; i<t; i++)
        {
            tempo=erros=questoes=0;
            for(j=0; j<p; j++)
            {
                scanf("%s", desc);
                size=strlen(desc);
                for(k=0; k<size; k++)
                    if(desc[k]=='/')
                    {
                        m=k;
                        break;
                    }
                if(desc[size-1]!='-')
                {
                    n=1;
                    for(k=size-1; k>m; k--)
                    {
                        tempo+=(desc[k]-'0')*n;
                        n*=10;
                    }
                    n=1;
                    for(k=m-1; k>=0; k--)
                    {
                        erros+=(desc[k]-'0')*n;
                        n*=10;
                    }
                    erros--;
                    questoes++;
                }
            }
            placar.push_back(make_pair(make_pair(questoes, tempo+erros*20), make_pair(erros, tempo)));
        }
        sort(placar.begin(), placar.end());
        aux=make_pair(make_pair(placar[0].first.first, placar[0].first.second), make_pair(placar[0].second.first, placar[0].second.second));
        for(i=1; i<t; i++)
        {
            if(aux.first.first==placar[i].first.first)
            {
                if(aux.first.second==placar[i].first.second)
                {
                    if(aux.second.first!=placar[i].second.first)
                        t1=t2=(placar[i].second.second-aux.second.second)/(aux.second.first-placar[i].second.first);
                }
                else
                {
                    if(aux.second.first!=placar[i].second.first)
                    {
                        if(aux.second.first>placar[i].second.first)
                        {
                            t1=(placar[i].second.second-aux.second.second)/(aux.second.first-placar[i].second.first);
                            if((placar[i].second.second-aux.second.second)%(aux.second.first-placar[i].second.first)==0) t1--;
                        }
                        else
                        {
                            t2=(placar[i].second.second-aux.second.second)/(aux.second.first-placar[i].second.first);
                            t2++;
                        }
                    }
                }
            }
            aux=make_pair(make_pair(placar[i].first.first, placar[i].first.second), make_pair(placar[i].second.first, placar[i].second.second));         
            tmax=min(tmax, t1);
            tmin=max(tmin, t2);
        }
        if(tmax==INF) printf("%d *\n", tmin);
        else printf("%d %d\n", tmin, tmax);
        placar.clear();      
    }
    return 0;    
}
