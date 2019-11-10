#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int i, t;
    char s[11111];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        int n=strlen(s), i, j;
        ll ans=1;
        for(i=0; i<n; ) {
            for(j=i; j<n && s[j]==s[i]; j++);
            if(s[i]=='?' && i && j<n && s[i-1]!=s[j]) ans=(ans*(j-i+1))%MOD;
            i=j;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
