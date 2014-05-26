#include <bits/stdc++.h>
using namespace std;

int dp[22][11][180];
int vis[22][11][180];

int go(int n, int k, int s) {
    if(s < 0 || n < 0 || k < 0) return 0;
    if(n == 0) return k == s && k == 0;
    vis[n][k][s] = 1;
    return dp[n][k][s] = go(n-1, k-1, s-k) + go(n-1, k, s-k);
}

int main() {
    int n, k, s;
    while(cin>>n>>k>>s && n) {
        for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
        for(int kk=0;kk<=s;kk++) vis[i][j][kk] = 0;
        cout << go(n, k, s) << endl;
    }
    return 0;
}
