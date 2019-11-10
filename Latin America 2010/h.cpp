#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MOD 100000000

using namespace std;

vector<pair<int, int> > v;
int dp[105][105];

int main()
{
    int i, j, k, n, m, s, f, resp;
    while(scanf("%d %d", &m, &n) && (m || n))
    {
        v.clear();
        for(i=0; i<n; i++)
        {
            scanf("%d %d", &s, &f);
            v.push_back(make_pair(s, f));
            for(j=0; j<n; j++) dp[i][j]=0;
        }
        sort(v.begin(), v.end());
        for(i=0; i<n; i++)
            if(!v[i].first)
            {
                dp[i][i]=1;
                for(j=i+1; j<n; j++)
                    if(v[j].first>v[i].first && v[j].first<=v[i].second && v[j].second>v[i].second)
                        dp[i][j]=1;
            }
        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
                if(v[j].first>v[i].first && v[j].first<=v[i].second && v[j].second>v[i].second)
                    for(k=0; k<=i; k++)
                        if(v[j].first>v[k].second)
                            dp[i][j]+=dp[k][i];
        resp=0;
        for(j=0; j<n; j++) for(i=0; i<=j; i++) if(v[j].second==m) resp=(resp+dp[i][j])%MOD;
        printf("%d\n", resp);
    }
    return 0;
}
