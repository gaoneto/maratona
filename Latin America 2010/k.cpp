#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef struct {
    int num;
    int amigo[2];
    int n;
    int vis;
    int ind;
}kid;

int flag;
map<int, set<int> > grafo;
map<int, int> pos;
vector<kid> v;
map<int, set<int> >::iterator it;
set<int>::iterator it1;

void bfs(int s)
{
    kid u, j;
    int i, w, z;
    queue<kid> q;
    v[s].vis=1;
    q.push(v[s]);
    while(!q.empty())
    {
        u=q.front();
        z=u.ind;
        q.pop();
        for(i=0; i<u.n; i++)
        {
            w=u.amigo[i];
            j=v[pos[w]];
            if(v[j.ind].vis==0)
            {
                v[j.ind].vis=1;
                q.push(v[j.ind]);
            }
            else if(v[j.ind].vis==1) 
            {
                flag++;
                if(flag>1) return;
            }
        }
        v[z].vis=2;
    }
}

int main()
{
    int i, k, w, a, b, u, x, m, aux, cont;
    while(scanf("%d %d", &k, &w) && (k || w))
    {
        grafo.clear();
        v.clear();
        pos.clear();
        flag=m=cont=0;
        for(i=0; i<w; i++)
        {
            scanf("%d %d", &a, &b);
            grafo[a].insert(b);
            grafo[b].insert(a);
            if(grafo[a].size()>2 || grafo[b].size()>2) flag=1;
        }
        for(it=grafo.begin(); it!=grafo.end(); it++)
        {
            kid k;
            u=(*it).first;
            k.num=u;
            k.n=grafo[u].size();
            k.vis=0;
            k.ind=cont;
            pos[u]=cont++;
            aux=0;
            m+=(*it).second.size();
            for(it1=grafo[u].begin(); it1!=grafo[u].end(); it1++)
            {
                x=*it1;
                k.amigo[aux++]=x;
            }
            v.push_back(k);
        }
        if(w==0) printf("Y\n");
        else if(flag) printf("N\n");
        else
        {
            for(i=0; i<v.size(); i++)
            {
                if(!v[i].vis) bfs(i);
                if(flag>1) break;
            }
            if(flag>1) printf("N\n");
            else if(flag==1)
            {
                if(m==2*k) printf("Y\n");
                else printf("N\n");
            }
            else printf("Y\n");
        }
    }
    return 0;
}
