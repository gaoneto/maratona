#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;

    pt(double x=0, double y=0): x(x), y(y) {}

    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
    double operator %(pt p) { return x*p.y - y*p.x; }

    int prod(pt p, pt q) {
        double ret = (*this-p) % (q-p);
        if(ret > 1e-6) return 1;
        if(ret < -1e-6) return -1;
        return 0;
    }
};

double abs(pt p, pt q) {
    return hypot(p.x-q.x, p.y-q.y);
}

pt project(pt a, pt b) {
    return b * ((a*b) / (b*b));
}

double dist_pt_line(pt p, pt a, pt b) {
    return abs(p, a + project(p-a, b-a));
}

pt p[111];

int main() {
    int n, t=1;
    while(cin>>n && n) {
        double ans=1e9;
        for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
            int side=0, good=1;
            for(int k=0;k<n;k++) {
                int pr = p[k].prod(p[i], p[j]);
                if(pr) {
                    if(!side) side=pr;
                    else if(side != pr) good=0;
                }
            }
            if(good) {
                double aux=0;
                for(int k=0;k<n;k++) {
                    aux = max(aux, dist_pt_line(p[k], p[i], p[j]));
                }
                ans = min(ans, aux);
            }
        }
        printf("Case %d: %.2lf\n", t++, ans);
    }
    return 0;
}
