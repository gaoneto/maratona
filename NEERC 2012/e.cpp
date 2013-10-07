#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll x;
    int n;
    ull p10[20];
    p10[0] = 1;
    for(int i=1;i<=19;i++) p10[i] = 10*p10[i-1];
    while(scanf("%lld %d", &x, &n) != EOF) {
        vector<pair<ll, int> > v[20];
        for(int i=0;i<n;i++) {
            int k;
            ll q;
            cin>>k>>q;
            v[k].push_back(make_pair(p10[k]*q, i+1));
        }
        priority_queue<pair<ll, int> > q;
        ll sum=0;
        vector<int> ans;
        int i;
        for(i=0;i<=18;i++) {
            ll num = x % p10[i+1];
            for(int j=0;j<v[i].size();j++) q.push(v[i][j]);
            while(sum < num && !q.empty()) {
                 sum += q.top().first;
                 ans.push_back(q.top().second);
                 q.pop();
            }
            if(sum < num && q.empty()) break;
        }
        if(i <= 18) cout << -1 << endl;
        else {
            cout << ans.size() << endl;
            cout << ans[0];
            for(i=1;i<ans.size();i++) cout << " " << ans[i]; cout << endl;
        }
    }
    return 0;
}
