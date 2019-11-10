#include <bits/stdc++.h>
using namespace std;

char s[111111];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        int ans=0;
        scanf("%d %s", &n, s);
        for(int i=0; i<n; i++) if(s[i]=='1') ans++;
        printf("%lld\n", 1ll*ans*(ans+1)/2);
    }
    return 0;
}
