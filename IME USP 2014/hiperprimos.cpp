#include <bits/stdc++.h>
#define MAX 2000100
using namespace std;

int a[MAX], prime[MAX], nprimes=1, dp[MAX], divisors[MAX];

int main() {
    int n;
    prime[0]=2;
    for(int i=4; i<2000; i+=2) a[i]=1;
    for(int i=3; i<2000; i+=2) if(!a[i]) {
        prime[nprimes++]=i;
        for(int j=2*i; j<2000; j+=i) a[j]=1;
    }
    for(int i=2; i<MAX; i++) {
        n=i;
        divisors[n]=1;
        for(int j=0; prime[j]*prime[j]<=n; j++) if(n%prime[j]==0) {
            int e=0;
            while(n%prime[j]==0) {
                n/=prime[j];
                e++;
            }
            divisors[i]*=(e+1);
        }
        if(n!=1) divisors[i]*=2;
        if(!a[divisors[i]]) dp[i]=1;
    }
    for(int i=1; i<MAX; i++) dp[i]+=dp[i-1];
    while(scanf("%d", &n)!=EOF) printf("%d\n", dp[n]);
    return 0;
}
