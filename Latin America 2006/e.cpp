#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
#define all(v) (v).begin(), (v).end()

using namespace std;

const int INF = 0xFFFFFFF;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    static point pivot;
};

point point::pivot;
double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef vector<point> polygon;

int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

double angle(point p, point q, point r) {
    point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}

bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

polygon convex_hull(vector<point>& T) {
    int j = 0, k, n = T.size(); polygon U(n);
    point::pivot = *min_element(all(T));
    sort(all(T), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + all(T));
    for (int i = 0; i < n; i++) {
        // troque o >= por > para manter pontos colineares
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) > 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

int main()
{
    int i, j, k, n, cebola;
    double x, y;
    vector<point> c;
    while(scanf("%d", &n) && n)
    {
        c.clear();
        for(i=0; i<n; i++)
        {
            scanf("%lf %lf", &x, &y);
            point q(x, y);
            c.push_back(q);
        }
        cebola=0;
        while(c.size()>0)
        {
            polygon p;
            p=convex_hull(c);
            cebola++;
            for(i=0; i<p.size(); i++)
            {
                for(j=0; j<c.size(); j++)
                    if(c[j].x==p[i].x && c[j].y==p[i].y)
                        c.erase(c.begin()+j);
            }
        }
        if(cebola%2==0) printf("Do not take this onion to the lab!\n");
        else printf("Take this onion to the lab!\n");
    }
    return 0;
}
