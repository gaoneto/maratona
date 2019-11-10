#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#define INF 1000000000

using namespace std;

vector<pair<int, char> > mao[11], saque;
stack<pair<int, char> > baralho;
pair<int, char> descarte;

int main()
{
    int i, j, p, m, n, x, aux, sentido, num, vez, flag, ind, aux1, trocou;
    char s;
    while(scanf("%d %d %d", &p, &m, &n) && (p || m || n))
    {
        aux=vez=aux1=0;
        sentido=1;
        num=INF;
        for(i=0; i<n; i++)
        {
            scanf("%d %c", &x, &s);
            if(i<p*m)
            {
                mao[aux].push_back(make_pair(x, s));
                if(mao[aux].size()==m) aux++;
            }
            else if(i==p*m) descarte=make_pair(x, s);
            else saque.push_back(make_pair(x, s));
        }
        for(i=0; i<p; i++)
            sort(mao[i].begin(), mao[i].end());
        for(i=saque.size()-1; i>=0; i--)
            baralho.push(make_pair(saque[i].first, saque[i].second));
        while(num!=0)
        {
            flag=trocou=0;
            if(descarte.first==12 && aux1==0)
            {
                if(sentido==-1) sentido=1;
                else sentido=-1;
                aux1=1;
            }
            if(descarte.first==7 && aux1==0)
            {
                if(!baralho.empty())
                {
                    mao[vez].push_back(make_pair(baralho.top().first, baralho.top().second));
                    baralho.pop();
                }
                if(!baralho.empty())
                {
                    mao[vez].push_back(make_pair(baralho.top().first, baralho.top().second));
                    sort(mao[vez].begin(), mao[vez].end());
                    baralho.pop();
                }
                vez+=sentido;
                if(vez==p) vez=0;
                else if(vez==-1) vez=p-1;
                aux1=1;
                continue;
            }
            if(descarte.first==1 && aux1==0)
            {
                if(!baralho.empty())
                {
                    mao[vez].push_back(make_pair(baralho.top().first, baralho.top().second));
                    sort(mao[vez].begin(), mao[vez].end());
                    baralho.pop();
                }
                vez+=sentido;
                if(vez==p) vez=0;
                else if(vez==-1) vez=p-1;
                aux1=1;
                continue;             
            }
            if(descarte.first==11 && aux1==0)
            {
                vez+=sentido;
                if(vez==p) vez=0;
                else if(vez==-1) vez=p-1;
                aux1=1;
                continue;
            }
            for(i=mao[vez].size()-1; i>=0; i--)
                if(mao[vez][i].second==descarte.second || mao[vez][i].first==descarte.first)
                {
                    flag=1;
                    ind=i;
                    break;                                   
                }
            if(flag)
            {
                descarte=make_pair(mao[vez][ind].first, mao[vez][ind].second);
                trocou=1;
                mao[vez].erase(mao[vez].begin()+ind);
            }
            else
            {
                if(!baralho.empty())
                {
                    if(baralho.top().first==descarte.first || baralho.top().second==descarte.second)
                    {
                        descarte=make_pair(baralho.top().first, baralho.top().second);
                        trocou=1;
                    }
                    else
                    {
                        mao[vez].push_back(make_pair(baralho.top().first, baralho.top().second));
                        sort(mao[vez].begin(), mao[vez].end());
                    }
                    baralho.pop();
                }
            }
            for(i=0; i<p; i++)
                if(mao[i].size()<num)
                {
                    num=mao[i].size();
                    ind=i;
                }
            if(trocou && descarte.first==12) vez-=sentido;
            else vez+=sentido;
            if(vez==p) vez=0;
            else if(vez==-1) vez=p-1;
            if(trocou) aux1=0;
        }
        printf("%d\n", ind+1);
        saque.clear();
        for(i=0; i<p; i++)
            mao[i].clear();
        while(!baralho.empty())
            baralho.pop();
    }
    return 0;    
}
