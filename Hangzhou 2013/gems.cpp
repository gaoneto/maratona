#include <bits/stdc++.h>
using namespace std;

int g, b, s;

vector<int> bag[33];
int sum[10];
const int N=1e7;
int vis[N], val[N], T;

int go(int mask) {
    if(vis[mask] == T) return val[mask];
    int ret=-1000;
    for(int i=0;i<b;i++) {
        if(mask & (1<<i)) continue; 
        int aux=0;
        for(int j=0;j<bag[i].size();j++) {
            int c = bag[i][j];
            if(++sum[c] >= s) {
                sum[c] = 0;
                aux++;
            }
        }
        if(aux > 0) {
            ret = max(ret, aux + go(mask | (1<<i)));
        }
        else {
            ret = max(ret, aux - go(mask | (1<<i)));
        }
        for(int j=0;j<bag[i].size();j++) {
            int c = bag[i][j];
            if(--sum[c] < 0) {
                sum[c] = s-1;
            }
        }
    }
    vis[mask] = T;
    return val[mask] = ret;
}

int main() {
    while(cin>>g>>b>>s && s) {
        T++;
        for(int j=1;j<=g;j++) sum[j] = 0;
        for(int i=0;i<b;i++) {
            int n;
            cin>>n;
            bag[i].resize(n);
            for(int j=0;j<n;j++) cin>>bag[i][j];
        }
        int fim=0;
        for(int i=0;i<b;i++) fim += 1<<i;
        vis[fim] = T;
        val[fim] = 0;
        cout << go(0) << endl;
    }
    return 0;
}
