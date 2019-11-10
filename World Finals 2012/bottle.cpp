#include <bits/stdc++.h>
using namespace std;

const int N=1e6;
double p[22], vol[N+1];
    
int n;

double f(double x) {
    double ret=0;
    for(int i=n;i>=0;i--) {
        ret *= x;
        ret += p[i];
    }
    return ret;
}

int main() {
    int T=1;
    while(scanf("%d", &n) != EOF) {
        for(int i=0;i<=n;i++) cin>>p[i];
        double xlo, xhi, inc;
        cin>>xlo>>xhi>>inc;
        double eps = (xhi - xlo)/N;
        printf("eps = %lf\n", eps);
        for(int i=1;i<=N;i++) {
            double h = f(xlo + i*eps);
            vol[i] = vol[i-1] + eps * M_PI * h * h;
        }
        printf("Case %d: %.2lf\n", T++, vol[N]);
        if(vol[N] < inc - 1e-9) printf("insufficient volume\n");
        else {
            int j=0;
            for(int k=1;k<=8;k++) {
                int v = inc*k;
                while(j <= N && vol[j] < v - 1e-9) j++;
                if(j > N) break;
                if(k>1) printf(" ");
                printf("%.2lf", j*eps);
            }
            printf("\n");
        }
    }
    return 0;
}
