#include <bits/stdc++.h>
#include <cassert>
using namespace std;

typedef long long ll;

ll dpl[5555], dph[5555], dp[1111111];

const int mc = 1e6;
vector <pair<int,pair<int,char> > > v;
pair<int, char> ans[111111];
int h, l;

int solve(int c, int pos, int imax, int dep) {
    if(c == 0) {
        if(pos == dep) return 1;
        return 0;
    }
    if(pos >= dep) return 0;
    for(int i=imax;i>=0;i--) {
        if(c-v[i].first >= 0 && dp[c-v[i].first] != 1e9) {
            ans[pos] = v[i].second;
            if(solve(c - v[i].first, pos+1, i-1, dep)) return 1;
        }
    }
    return 0;
}

int main()
{
    dpl[1]=1;
    dpl[2] = 4;
    for(l=3;dpl[l-1]<1e6;l++) {
        dpl[l]=dpl[l-2]+l*l;
        v.push_back(make_pair(dpl[l],make_pair(l,'L')));
    }
    dph[1]=1;
    for(h=2;dph[h-1]<mc;h++) {
        dph[h]=dph[h-1]+h*h;
        v.push_back(make_pair(dph[h],make_pair(h,'H')));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<=mc;i++) dp[i] = 1e9;
    dp[0] = 0;
    for(int i=0;i<v.size();i++) {
        for(int j=mc-v[i].first;j>=0;j--) {
            if(dp[j+v[i].first] > dp[j]+1) dp[j+v[i].first] = dp[j]+1;
        }
    }
    int t = 1, c;
    while(scanf("%d", &c) && c) {
        printf("Case %d: ", t++);
        if(dp[c] == 1e9) printf("impossible\n");
        else {
            solve(c, 0, v.size()-1, dp[c]);
            for(int i=0;i<dp[c];i++) {
                if(i) printf(" ");
                printf("%d%c", ans[i].first, ans[i].second);
            }
            printf("\n");
        }
    }
    return 0;
}
