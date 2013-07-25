#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>
#define INF 1000000000
#define EPS 1e-8

using namespace std;

typedef long long ll;

vector<pair<int, int> > grafo[2010];
double dp[2010][2010], resp=0.0;

int main()
{
    int i, n, k, c, j, v, g, w;
    scanf("%d %d", &n, &k);
    for(i=0; i<=n; i++)
    {
        dp[i][0]=1;
        dp[i][1]=i;
        for(j=1; j<=i; j++) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
    for(i=1; i<n; i++) for(j=i+1; j<=n; j++)
    {
        scanf("%d", &c);
        if(c>-1)
        {
            grafo[i].push_back(make_pair(j, c));
            grafo[j].push_back(make_pair(i, c));
        }
    }
    for(i=1; i<=n; i++) for(j=0; j<grafo[i].size(); j++)
    {
        w=grafo[i][j].second;
        v=grafo[i][j].first;
        g=(int)grafo[v].size();
        resp+=(double)w*dp[g-1][k-1];
    }
    resp/=dp[n][k];
    cout << (ll)resp;
    return 0;
}
