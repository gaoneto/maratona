#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int c[1111], c0[1111], c1[1111];


int main() {
    int t=1;
    while(1) {
        int n;
        string a, b;
        cin>>n;
        if(n==0) return 0;
        cin>>a>>b;
        for(int i=0;i<n;i++) cin>>c[i];
        int n0=0, n1=0;
        for(int i=0;i<n;i++) {
            if(a[i]==b[i]) continue;
            if(a[i]=='0') c0[n0++] = c[i];
            else c1[n1++] = c[i];
        }
        sort(c0, c0+n0, greater<int>());
        sort(c1, c1+n1);
        ll v0=0, v1=0, vc=0;
        for(int i=0;i<n;i++) if(a[i]==b[i] && a[i]=='1') vc += c[i] * (n0 + n1);
        //for(int i=0;i<n0;i++) v0 += c0[i] * i;
        //for(int i=0;i<n1;i++) v1 += c1[i] * (i+1);
        printf("Case %d: ", t++);
        cout<<v0+v1+vc<<endl;
    }
}
