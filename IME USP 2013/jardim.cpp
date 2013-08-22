#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const double PI = acos(-1);

int n, l, d;
int h[111];

int main() {
    while(scanf("%d %d %d", &n, &l, &d) != EOF) {
        for(int i=0;i<n;i++) cin>>h[i];
        int pos;
        for(int i=0;i<n;i++) if(h[i]==0) pos=i;
        double t1=0, t2=0;
        for(int i=0;i<pos;i++) {
            double aux;
            aux = atan2(h[pos-i-1], (l+d)*(i+1));
            t1 = max(t1, aux);
        }
        for(int i=pos+1;i<n;i++) {
            double aux;
            aux = atan2(h[i], (l+d)*(i-pos));
            t2 = max(t2, aux);
        }
        printf("%.2lf\n", (PI - t1 - t2) * 16 * 60 / PI);
    }
    return 0;
}
