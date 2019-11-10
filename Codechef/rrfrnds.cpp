#include <bits/stdc++.h>
using namespace std;

bitset<2000> adj[2000];

int main() {
    int n;
    char s[2222];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        for(int j=0; j<n; j++) adj[i][j]=s[j]-'0';
    }
    int ans=0;
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(!adj[i][j] && (adj[i]&adj[j]).any()) ans+=2;
    printf("%d\n", ans);
    return 0;
}
