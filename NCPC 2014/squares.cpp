#include <bits/stdc++.h>
#define EPS 1e-6
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

struct pt {
    double x, y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(double c) { return pt(x*c, y*c); }
    double operator *(pt p) { return x*p.x + y*p.y; }
};

//retorna distancia entre dois pontos, se apenas um for passado, considera o outro a origem
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }

//retorna a projecao do ponto a no ponto b
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

//distancia entre um ponto e uma reta
double dist_pt_line(pt p, pt a, pt b = pt()) { return abs(p, a + project(p-a, b-a)); }

int main() {
    int n, t=0, ans=0;
    map<pii, int> m;
    vector<pair<pt, pt> > v[2222];
    vector<double> d[2222];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x1, y1, x2, y2, dx, dy, mdc;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        dx=x1-x2, dy=y1-y2;
        if(dy<=0) {
			if(dy<0) dx=-dx, dy=-dy;
			else if(dx<0) dx=-dx;
		}
        mdc=__gcd(abs(dx), abs(dy));
        dx/=mdc, dy/=mdc;
        if(!m.count(pii(dx, dy))) m[pii(dx, dy)]=t++;
        int id=m[pii(dx, dy)];
        v[id].push_back(make_pair(pt(x1, y1), pt(x2, y2)));
    }
    for(int i=0; i<t; i++) for(int j=0; j<v[i].size(); j++) for(int k=j+1; k<v[i].size(); k++) d[i].push_back(dist_pt_line(v[i][j].f, v[i][k].f, v[i][k].s));
    for(int i=0; i<t; i++) sort(d[i].begin(), d[i].end());
    for(map<pii, int>::iterator it=m.begin(); it!=m.end(); it++) {
        int a=it->f.f, b=it->f.s;
        int na=-b, nb=a;
        if(nb<=0) {
			if(nb<0) na=-na, nb=-nb;
			else if(na<0) na=-na;
		}
        if(!m.count(pii(na, nb))) continue;
        a=it->s, b=m[pii(na, nb)];
        int pa=0, pb=0;
        for(int i=0; i<d[a].size(); ) {
            int cnta=0, cntb=0;
            for(; pa<d[a].size() && fabs(d[a][i]-d[a][pa])<EPS; cnta++, pa++);
            for(; pb<d[b].size() && d[b][pb]<d[a][pa-1]+EPS; pb++) if(fabs(d[b][pb]-d[a][pa-1])<EPS) cntb++;
            ans+=cnta*cntb;
            i=pa;
        }
    }
    printf("%d\n", ans/2);
    return 0;
}
