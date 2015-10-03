#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-6

using namespace std;
const int N=2e3+10;

inline int cmpD (double a, double b=0, double tol=EPS) { return a+tol < b ? -1: a-tol > b; }

struct pt {
    double x, y, z, r;

    pt(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}

    pt operator +(const pt &p) const { return pt(x + p.x, y + p.y, z + p.z); }
    pt operator -(const pt &p) const { return pt(x - p.x, y - p.y, z - p.z); }
    pt operator *(double c) const { return pt(x*c, y*c, z*c); }
    pt operator /(double c) const { return pt(x/c, y/c, z/c); }
    double operator !() const { return sqrt(x*x + y*y + z*z); }
	bool operator !=(const pt &p) const { return cmpD(!(*this - p)) != 0; }
	bool operator ==(const pt &p) const { return not(*this != p); }

    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << "," << p.z << ")"; }
};

//retorna o produto escalar entre os pontos a e b
double dot(pt a, pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; }

//retorna a projecao do ponto b no ponto a
pt project(pt a, pt b) { return b * dot(a, b) / dot(b, b); }

//retorna a projecao do ponto p na reta ab
pt project(pt p, pt a, pt b) { return a + project(p-a, b-a); }

//retorna a distancia entre o ponto p e o segmento ab
double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = project(p, a, b);
    if(cmpD(!(a-pp) + !(pp-b), !(a-b)) == 0) return !(pp - p);
    return min(!(p - a), !(p - b));
}

int main() {
    int n, m, r;
    pt s[N], t[22], e;
    bitset<N> b[22];
    while(scanf("%d %d %d", &n, &m, &r) && (n | m | r)) {
        for(int i=0; i<n; i++) scanf("%lf %lf %lf %lf", &s[i].x, &s[i].y, &s[i].z, &s[i].r);
        for(int i=0; i<m; i++) scanf("%lf %lf %lf %lf", &t[i].x, &t[i].y, &t[i].z, &t[i].r);
        scanf("%lf %lf %lf", &e.x, &e.y, &e.z);
        double ans=0;
        for(int i=0; i<m; i++) b[i].reset();
        for(int i=0; i<m; i++) for(int j=0; j<n; j++) {
            if(cmpD(!(s[j]-t[i]), s[j].r)!=1 && cmpD(!(s[j]-e), s[j].r)!=1) continue;
            double d=dist_pt_seg(s[j], e, t[i]);
            if(cmpD(d, s[j].r)!=1) b[i][j]=1;
        }
        for(int i=1; i<(1<<m); i++) {
            bitset<N> aux;
            double tot=0;
            for(int j=0; j<m; j++) if(i&(1<<j)) {
                aux|=b[j];
                tot+=(t[j].r/((!(t[j]-e))*(!(t[j]-e))));
            }
            if((int)aux.count()>r) continue;
            ans=max(ans, tot);
        }
        printf("%.5lf\n", ans);
    }
    return 0;
}
