#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<int, ll> vis;

ll go(int n) {
    if(n<0) return 0;
    if(vis.count(n)) return vis[n];
    ll p;
    for(int i=0;i<64;i++) {
        if((1ll<<i) > n) {
            p = 1ll<<(i-1);
            break;
        }
    }
    if(p>n) cout<<"MERDA"<<endl;
    ll ret=n-p+1 + go(n-p);
    return vis[n] = ret + go(p-1);
}

int main() {
    int a, b;
    vis[0] = 0;
    vis[1] = 1;
    int t=1;
    while(1) {
        cin>>a>>b;
        if(a==0 && b==0) break;
        printf("Case %d: ", t++);
        if(a==0) cout<<go(b)<<endl;
        else cout << go(b) - go(a-1) << endl;
    }
    return 0;
}
