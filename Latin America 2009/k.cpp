#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;

vector<int> v[10010];

int mod(int a)
{
    return ((a>0) ? a : -a);
}

int bb(int i, int n, int x)
{
    int l, r, m;
    l=0; r=n-1;
    while(l<r) 
    {
        m=(l+r)/2;
        if(v[i][m]<x) l=m+1;
        else r=m;
    }
    if(v[i][r]<x) return r+1;
    return r;
}

int main()
{
    int i, j, l, minimo, maximo, n, k, t, nota, cont, ind, s[1001];
    while(scanf("%d", &n) && n)
    {
        minimo=INF;
        maximo=0;
        for(i=0; i<1001; i++) s[i]=0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &k);
            v[i].clear();
            for(j=0; j<k; j++)
            {
                scanf("%d", &nota);
                if(nota>maximo) maximo=nota;
                s[nota]=1;
                v[i].push_back(nota);
            }
        }
        for(i=0; i<n; i++) sort(v[i].begin(), v[i].end());
        for(i=0; i<=maximo; i++)
            if(s[i])
            {
                cont=0;
                for(j=0; j<n; j++)
                {
                    ind=bb(j, v[j].size(), i);
                    cont+=mod(v[j].size()-2*ind);
                }
                if(cont<minimo) minimo=cont;
            }
        printf("%d\n", minimo);
    }
    return 0;
}
