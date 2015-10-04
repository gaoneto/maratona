#include <bits/stdc++.h>
using namespace std;
#define MAX 150

int main() {
    int p, q, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &p, &q);
        int div=0;
        for(int m=-MAX; m<=MAX; m++) for(int n=-MAX; n<=MAX; n++) if(m || n) {
            if(abs(m*p+n*q)%(m*m+n*n)==0 && abs(m*q-n*p)%(m*m+n*n)==0) div++;
        }
        printf("%s\n", div==8 ? "P" : "C");
    }
    return 0;
}
