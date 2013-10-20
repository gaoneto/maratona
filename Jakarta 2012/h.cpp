#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

map<int, set<pii> > m;

void add(ll x, ll y, int i) { m[x].insert(pii(y, i)); }

void printa(ll x, ll y, int p)
{
	cout << (x+y)/2 << " " << (y-x)/2 << " " << p << " -> ";
	cout << x << " " << y << " " << p << endl;
}

void print()
{
	for(map<int, set<pii> >::iterator it = m.begin(); it != m.end(); it++)
	{
		set<pii> s=it->second;
		for(set<pii>::iterator its = it->second.begin(); its != it->second.end(); its++) printa(it->first, its->first, its->second);
		cout << endl;
	}
}

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cout << "Case #" << t << ":" << endl;
        int n, q;
        ll w, h;
        scanf("%d %d %lld %lld", &n, &q, &w, &h);
        m.clear();
        vector<pii> ans(n);
        for(int i=0;i<n;i++) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
			ans[i] = pii(x, y);
            add(x-y, x+y, i);
        }
        while(q--) {
            ll E, a, b, c, d, e, f, x, y;
            scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &x, &y, &E, &a, &b, &c, &d, &e, &f);
            ll nx = x-y, ny=x+y;
            ll minx = nx - E, maxx = nx + E;
            ll miny = ny - E, maxy = ny + E;
            map<int, set<pii> >::iterator it = m.upper_bound(maxx);
            if(it == m.begin()) continue;
            it--;
            vector<pair<pii, int> > vadd;
            while(1) {
                if(it->first < minx) break;
                set<pii>::iterator its = it->second.upper_bound(pii(maxy, n));
                if(its != it->second.begin())
				{
					its--;
					while(1) {
						if(its->first < miny) break;
						ll oldx = it->first, oldy = its->first;
						int pos = its->second;
						ll A=(oldx+oldy)/2, B=(oldy-oldx)/2;
						nx = ((A * a) + (B * b) + ((pos+1)*c)) % w;
						ny = ((A * d) + (B * e) + ((pos+1)*f)) % h;
						ans[pos] = pii(nx, ny);
						vadd.push_back(make_pair(pii(nx-ny, nx+ny), pos));
						if(its == it->second.begin()) {
							it->second.erase(its);
							break;
						}
						else {
							it->second.erase(its--);
						}
					}
				}
                if(it->second.size() == 0) {
                    if(it == m.begin()) {
                        m.erase(it);
                        break;
                    }
                    else {
                        m.erase(it--);
                    }
                }
                else {
                    if(it == m.begin()) break;
                    else it--;
                }
            }
            for(int i=0;i<vadd.size();i++) add(vadd[i].first.first, vadd[i].first.second, vadd[i].second);
		}
        for(int i=0;i<n;i++) cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
