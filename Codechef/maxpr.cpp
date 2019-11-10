#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int sum[111][222], a[222222];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(sum, 0, sizeof(sum));
        int ans=0, tot=1;
        for(int i=0; i<n; i++) scanf("%d", &a[i]), tot=(tot*2)%MOD;
        tot=(tot-1+MOD)%MOD;
        for(int d=-100; d<=100; d++) {
            for(int i=0; i<n; i++) {
                int dp=1;
                if(a[i]-d>=1 && a[i]-d<=100) dp+=sum[a[i]-d][d+100];
                sum[a[i]][d+100]+=dp;
                if(sum[a[i]][d+100]>=MOD) sum[a[i]][d+100]-=MOD;
                ans+=dp;
                if(ans>=MOD) ans-=MOD;
            }
            ans=(ans-n+MOD)%MOD;
        }
        ans=(ans+n)%MOD;
        printf("%d\n", (tot-ans+MOD)%MOD);
    }
    return 0;
}
