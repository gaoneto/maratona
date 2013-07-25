#include <stdio.h>
#include <set>
#include <iostream>
#include <vector>
#include <string.h>
#define MMAX 10000

using namespace std;

string text[20], pattern;
vector<int> match;
int pi[MMAX], l[20], r[20];

void build_prefix_function(int m) 
{
    int q, k;
    pi[0]=0;
    k=0;
    for(q=1; q<m; ++q) 
    {
        while(k>0 && pattern[k]!=pattern[q]) k=pi[k-1];
        if(pattern[k]==pattern[q]) ++k;
        pi[q]=k;
    }
}

int knuth_morris_pratt(int m, int j) 
{
    int q, i, n, tot=0;
    n=text[j].length(); 
    q=0;
    for(i=0; i<n; i++) 
    {
        while(q>0 && pattern[q]!=text[j][i]) q=pi[q-1];
        if(pattern[q]==text[j][i]) ++q;
        if(q==m) 
        { 
            tot++;
            if(tot>r[j]) return 0;
            q=pi[q-1]; 
        }
    }
    if(tot<l[j]) return 0;
    return 1;
}

int main()
{
    int i, j, n, size, k, flag, minimo=10000000;
    string s;
    set<string> se;
    cin >> s >> n;
    for(i=0; i<n; i++)
    {
        cin >> text[i] >> l[i] >> r[i];
        if(text[i].length()<minimo) minimo=text[i].length();
    }
    size=s.length();
    if(!n)
    {
        cout << size*(size+1)/2;
        return 0;
    }
    for(i=0; i<size; i++) for(j=i; j<size; j++)
    {
        if((j-i+1)>minimo) break;
        pattern=s.substr(i, j-i+1);
        build_prefix_function(j-i+1);
        flag=0;
        for(k=0; k<n; k++)
        {
            if(!knuth_morris_pratt(j-i+1, k))
            {
                flag=1;
                break;
            }
        }
        if(!flag) se.insert(pattern);
    }
    cout << se.size();
    return 0;    
}
