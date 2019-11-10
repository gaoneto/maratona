#include <bits/stdc++.h>
using namespace std;

double p[33], s[33];
    
int n;
double xlo, xhi;

double f(double x) {
    double ret=0;
    for(int i=n;i>=0;i--) {
        ret *= x;
        ret += s[i];
    }
    return M_PI*ret;
}

void square() {
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) s[i+j] += p[i]*p[j];
}

void integrate() {
    for(int i=n;i>=0;i--) s[i+1] = s[i]/(i+1);
}

double bin(double v) {
    double lo=xlo, hi=xhi+1, mi;
    for(int i=0;i<200;i++) {
        mi = (lo+hi)/2;
        if(f(mi)-f(xlo) > v) hi = mi;
        else lo = mi;
    }
    return mi;
}

int main() {
    int T=1;
    while(scanf("%d", &n) != EOF) {
        for(int i=0;i<=n;i++) cin>>p[i];
        memset(s,0,sizeof(s));
        double inc;
        cin>>xlo>>xhi>>inc;
        square();
        n *= 2;
        integrate();
        n++;
        double vol = (f(xhi)-f(xlo));
        printf("Case %d: %.2lf\n", T++, vol);
        if(vol < inc - 1e-9) printf("insufficient volume\n");
        else {
            for(int i=1;i<=8;i++) {
                double h = bin(i*inc);
                if(h > xhi) break;
                if(i > 1) printf(" ");
                printf("%.2lf", h-xlo);
            }
            cout << endl;
        }
    }
    return 0;
}
