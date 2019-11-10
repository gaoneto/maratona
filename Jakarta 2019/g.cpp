#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> B[N];
int a[N], r[N], pos[N];

typedef struct {
	int _max;
    int lazy;
} interval;

interval M[4*N];

interval join(interval i1, interval i2) {
    interval i;
	i.lazy=0;
	i._max=max(i1._max, i2._max);
    return i;
}

void init(int node, int b, int e) {
    if(b==e) M[node]._max=pos[b];
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
		M[node]._max+=M[node].lazy;
        M[node].lazy=0;
    }
    if(i>e || j<b) {
        p1._max=-1;
        return p1;
    }
    if(b>=i && e<=j) return M[node];
    p1=query(2*node, b, (b+e)/2, i, j);
    p2=query(2*node+1, (b+e)/2+1, e, i, j);
    if(p1._max==-1) return p2;
    if(p2._max==-1) return p1;
    return join(p1, p2);
}

void update(int node, int b, int e, int i, int j, int v) {
    if(M[node].lazy) {
        if(b!=e) {
            M[2*node].lazy+=M[node].lazy;
            M[2*node+1].lazy+=M[node].lazy;
        }
		M[node]._max+=M[node].lazy;
        M[node].lazy=0;
    }
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
		M[node]._max+=v;
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

int main() {
	int n, m, q, p, cnt;
	scanf("%d %d %d", &n, &m, &q);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	p=a[0];
	pos[0]=cnt=1;
	for(int i=1; i<n; i++) if(a[i]>p) pos[0]++, cnt++;
	for(int i=0; i<m; i++) {
		scanf("%d", &r[i]);
		for(int j=0; j<r[i]; j++) {
			int v;
			scanf("%d", &v);
			B[i].push_back(v);
			if(v>p) cnt++;
		}
		pos[i]+=r[i];
		pos[i+1]=cnt;
	}
	init(1, 0, m);
	for(int i=0; i<q; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		x--, y--;
		if(z>p && B[x][y]<p) update(1, 0, m, x+1, m, 1);
		else if(z<p && B[x][y]>p) update(1, 0, m, x+1, m, -1);
		interval iq=query(1, 0, m, 0, m);
		printf("%d\n", iq._max>n ? 0 : 1);
		B[x][y]=z;
	}
	return 0;
}
