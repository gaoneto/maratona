#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;

int n, w, x[N], dp[N], s[N];

int valid(int v) {
    int k=0, sum;
    dp[0]=1;
    for(int i=1; i<=n; i++) dp[i]=0;
    for(int i=1; i<=n; i++) if(dp[i-1]) for(int j=max(k, i+1); j<=n; j++) {
        sum=s[j]-s[i-1]+j-i;
        if(sum>w) break;
        int left=w-sum;
        int val=left/(j-i)+((left%(j-i))>0)+1;
        if(val<=v) dp[j]=1, k=j;
    }
    sum=s[n]-s[k]+n-k-1;
    if(sum<=w) return 1;
    return 0;
}

int main() {
    while(scanf("%d %d", &w, &n) && (w || n)) {
        int lo=1, mid, hi=w;
        for(int i=1; i<=n; i++) {
            scanf("%d", &x[i]);
            s[i]=s[i-1]+x[i];
        }
        while(lo<hi) {
            mid=(lo+hi)/2;
            if(valid(mid)) hi=mid;
            else lo=mid+1;
        }
        printf("%d\n", lo);
    }
    return 0;
}
