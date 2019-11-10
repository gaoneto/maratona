#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <utility>
#define MMAX 1000

using namespace std;

vector<char> text, pattern[100];
vector<pair<int, int> > match; 
int pi[MMAX];

void build_prefix_function(int j) 
{
    int m, q, k;
    m=pattern[j].size(); 
    pi[0]=0;
    k=0;
    for(q=1; q<m; ++q) 
    {
        while(k>0 && pattern[j][k]!=pattern[j][q]) k=pi[k-1];
        if(pattern[j][k]==pattern[j][q]) ++k;
        pi[q]=k;
    }
}

void knuth_morris_pratt(int j, int size) 
{
    int n, m, q, i;
    n=text.size(); 
    m=pattern[j].size();
    q=0;
    for(i=0; i<n; i++) 
    {
        while(q>0 && pattern[j][q]!=text[i]) 
            q=pi[q-1];
        if(pattern[j][q]==text[i]) ++q;
        if(q==m) 
        { 
            match.push_back(make_pair(i-m+size, i-m+1));
            q=pi[q-1]; 
        }
    }
}

int main()
{
    int n, m, i, j, k, size, total;
    char emoticon[150][200], texto[1000];
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        for(i=0; i<n; i++)
        {
            pattern[i].clear();
            scanf("%s", emoticon[i]);
            size=strlen(emoticon[i]);
            for(j=0; j<size; j++)
                pattern[i].push_back(emoticon[i][j]);
        }
        total=0;
        for(i=0; i<m; i++)
        {
            getchar();
            texto[0]='\0';
            scanf("%[^\n]s", texto);
            text.clear();
            match.clear();
            size=strlen(texto);
            for(j=0; j<size; j++)
                text.push_back(texto[j]);
            for(j=0; j<n; j++)
            {
                build_prefix_function(j);
                knuth_morris_pratt(j, pattern[j].size());
            }
            sort(match.begin(), match.end());
            k=0;
            if(match.size()>0) total++;
            for(j=0; j<match.size(); j++)
                if(match[k].first<match[j].second)
                {
                    k=j;
                    total++;
                }
        }
        printf("%d\n", total);
    }
}
