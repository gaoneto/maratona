#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n, v[111];
vector<int> obj[111];

void print(ll x) {
    cout<<x<<":";
    vector<int> ans;
    for(int i=0;i<n;i++) {
        int j;
        for(j=0;j<obj[i].size();j++) if(obj[i][j] == x) break;
        if(j != obj[i].size()) ans.push_back(v[i]);
    }
    cout<<ans[0];
    for(int i=1;i<ans.size();i++) cout<<" "<<ans[i];
    cout<<endl;
}

int main() {
    while(1) {
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++) {
            cin>>v[i];
            obj[i].clear();
            obj[i].push_back(1);
            ll curr=v[i];
            ll inc = v[i]-2;
            ll delta=2*inc+1;
            ll max_value = 1ll<<32;
            while(1) {
                obj[i].push_back(curr);
                curr += delta;
                delta += inc;
                if(curr>max_value) break;
            }
        }
        int s;
        cin>>s;
        priority_queue<int> q;
        for(int i=0;i<n;i++) {
            vector<int> aux;
            for(int j=0;j<obj[i].size();j++) if(obj[i][j] >= s) aux.push_back(obj[i][j]);
            obj[i] = aux;
        }
        vector<int> t[25];
        for(int i=1;i<n/2;i++) merge(obj[2*i].begin(), obj[2*i].end(), obj[2*i+1].begin(), obj[2*i+1].end(), t[i].begin());
    }
    return 0;
}
