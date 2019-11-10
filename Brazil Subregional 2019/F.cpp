#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e4+10, C=1e5+10;
int n, p, xr1[N], yr1[N], xr2[N], yr2[N], xt1, yt1, xt2, yt2;

typedef struct {
    int _min;
	int count;
    int lazy;
} interval;

interval M[4*C];

interval join(interval i1, interval i2) {
    interval i;
	i._min=min(i1._min, i2._min);
	i.lazy=0;
	if(i1._min<i2._min) i.count=i1.count;
	else if(i1._min>i2._min) i.count=i2.count;
	else i.count=i1.count+i2.count;
    return i;
}

void init(int node, int b, int e) {
    if(b==e) {
        M[node].count=1;
        M[node]._min=0;
    }
    else {
        int m=(b+e)/2;
        init(2*node, b, m);
        init(2*node+1, m+1, e);
        M[node]=join(M[2*node], M[2*node+1]);
    }
    M[node].lazy=0;
}

interval query(int node, int b, int e, int i, int j) {
    interval p1, p2;
    if(M[node].lazy) {
        if(b!=e) {
            M[2*node].lazy+=M[node].lazy;
            M[2*node+1].lazy+=M[node].lazy;
        }
		M[node]._min+=M[node].lazy;
        M[node].lazy=0;
    }
    if(i>e || j<b) {
        p1._min=-1;
        return p1;
    }
    if(b>=i && e<=j) return M[node];
    p1=query(2*node, b, (b+e)/2, i, j);
    p2=query(2*node+1, (b+e)/2+1, e, i, j);
    if(p1._min==-1) return p2;
    if(p2._min==-1) return p1;
    return join(p1, p2);
}

void update(int node, int b, int e, int i, int j, int v) {
    if(M[node].lazy) {
        if(b!=e) {
            M[2*node].lazy+=M[node].lazy;
            M[2*node+1].lazy+=M[node].lazy;
        }
		M[node]._min+=M[node].lazy;
        M[node].lazy=0;
    }
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
		M[node]._min+=v;
        if(b!=e) {
            M[2*node].lazy+=v;
            M[2*node+1].lazy+=v;
        }
    }
    else {
        update(2*node, b, (b+e)/2, i, j, v);
        update(2*node+1, (b+e)/2+1, e, i, j, v);
        M[node]=join(M[2*node], M[2*node+1]);
    }
}

bool valid(int r) {
	vector<pair<int, pair<int, pair<int, int> > > > event;
	init(1, 0, yt2-1);
	for(int i=0; i<n; i++) {
		int xn1=xr1[i]-r, yn1=yr1[i]-r, xn2=xr2[i]+r, yn2=yr2[i]+r;
		xn1=max(xn1, xt1), xn2=max(xn2, xt1), yn1=max(yn1, yt1), yn2=max(yn2, yt1);
		xn1=min(xn1, xt2), xn2=min(xn2, xt2), yn1=min(yn1, yt2), yn2=min(yn2, yt2);
		event.push_back(make_pair(xn1, make_pair(0, make_pair(yn1, yn2))));
		event.push_back(make_pair(xn2, make_pair(1, make_pair(yn1, yn2))));
	}
	sort(event.begin(), event.end());
	ll area=0;
	int xl=event[0].first;
	for(int i=0; i<event.size(); i++) {
		int xe=event[i].first;
		int type=event[i].second.first;
		int yl=event[i].second.second.first;
		int yh=event[i].second.second.second;
		if(xl!=xe) {
			interval iq=query(1, 0, yt2-1, yt1, yt2-1);
			if(!iq._min) area+=1ll*(xe-xl)*(yt2-yt1-iq.count);
			else area+=1ll*(xe-xl)*(yt2-yt1);
		}
		if(!type) update(1, 0, yt2-1, yl, yh-1, 1);
		else update(1, 0, yt2-1, yl, yh-1, -1);
		xl=xe;
	}
	return area*100>=1ll*p*(xt2-xt1)*(yt2-yt1);
}

int go() {
	int lo=0, mid, hi=C;
	while(lo<hi) {
		mid=(lo+hi)/2;
		if(valid(mid)) hi=mid;
		else lo=mid+1;
	}
	return lo;
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d %d %d", &xr1[i], &yr1[i], &xr2[i], &yr2[i]);
		if(xr1[i]>xr2[i] || (xr1[i]==xr2[i] && yr1[i]>yr2[i])) swap(xr1[i], xr2[i]), swap(yr1[i], yr2[i]);
	}
	scanf("%d", &p);
	scanf("%d %d %d %d", &xt1, &yt1, &xt2, &yt2);
	printf("%d\n", go());
	return 0;
}
