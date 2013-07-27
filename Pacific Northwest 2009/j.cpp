#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef pair<int, int> pt;
#define x first
#define y second
#define INF 1e15
#define L 1000000
#define mp make_pair
typedef long long ll;

int mod(int a) { return a>0?a:-a; }

double abs(pt a, pt b) {
    return hypot(a.x - b.x, a.y - b.y);
}

ll cross(pt a, pt b) {
    return 1ll*a.x*b.y - 1ll*a.y*b.x;
}

int colinear(pt a, pt b, pt c) {
    ll s = cross(b, c) - cross(a, c) + cross(a, b);
    return s == 0;
}

int main() {
    int x1, y1, x2, y2;
    int n;
    while(1) {
        cin>>x1>>y1>>x2>>y2>>n;
        if(n==0) break;
        vector<pair<double, pt> > v;
        int i, j;
        for(i=-n;i<=n;i++) for(j=-n;j<=n;j++) {
            if(mod(i) + mod(j) > n) continue;
            int nx, ny;
            if(i%2==0) {
                nx = i*L + x2;
            } else {
                nx = i*L + (L-x2);
            }
            if(j%2==0) {
                ny = j*L + y2;
            } else {
                ny = j*L + (L-y2);
            }
            //printf("i=%d, j=%d\n", i, j);
            //printf("x1 = %lf, y1 = %lf, nx=%lf, ny=%lf\n", x1, y1, nx, ny);
            double d = abs(pt(nx, ny), pt(x1, y1));
            //printf("d=%.6lf\n", d);

            v.push_back(mp(d, pt(nx, ny)));
        }
        sort(v.begin(), v.end());
        //for(int i=0;i<v.size();i++) printf("%.6lf ", v[i].first);
        //cout<<endl;
        double best=INF;
        for(int i=0;i<v.size();i++) {
            int j;
            for(j=i+1;j<v.size();j++) if(!colinear(v[i].second, pt(x1, y1), v[j].second)) break;
            if(j < v.size()) best = min(best, v[j].first-v[i].first);
            //cout<<i<<" "<<j<<" "<<best<<endl;
        }
        printf("%.5lf\n", best);
    }
    return 0;
}
