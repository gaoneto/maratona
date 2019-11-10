#include <bits/stdc++.h>
using namespace std;

char s[111111];

int is_pal() {
    int n=strlen(s), i;
    for(int i=0; 2*i<n; i++) if(s[i]!=s[n-i-1]) return 0;
    return 1;
}

int solve() {
    if(is_pal()) return 1;
    return 2;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        printf("%d\n", solve());
    }
    return 0;
}
