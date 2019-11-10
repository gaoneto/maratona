#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10, MOD=1e9+7;
char s[N];

typedef struct {
    ll a1, b1, a2, b2;
    int lazy;
} interval;

interval M[4*N];

interval join(interval i1, interval i2) {
    interval i;
	i.lazy=0;
	i.a1=((i1.a1*i2.a1)%MOD+(i1.a2*i2.b1)%MOD)%MOD;
	i.b1=((i1.b1*i2.a1)%MOD+(i1.b2*i2.b1)%MOD)%MOD;
	i.a2=((i1.a1*i2.a2)%MOD+(i1.a2*i2.b2)%MOD)%MOD;
	i.b2=((i1.b1*i2.a2)%MOD+(i1.b2*i2.b2)%MOD)%MOD;
    return i;
}

void init(int node, int b, int e) {
    if(b==e) {
		if(s[b]=='A') M[node].a1=M[node].b1=M[node].b2=1, M[node].a2=0;
		else M[node].a1=M[node].a2=M[node].b2=1, M[node].b1=0;
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
		if((M[node].lazy)&1) {
			swap(M[node].a1, M[node].b2);
			swap(M[node].b1, M[node].a2);
		}
        M[node].lazy=0;
    }
    if(i>e || j<b) {
        p1.a1=-1;
        return p1;
    }
    if(b>=i && e<=j) return M[node];
    p1=query(2*node, b, (b+e)/2, i, j);
    p2=query(2*node+1, (b+e)/2+1, e, i, j);
    if(p1.a1==-1) return p2;
    if(p2.a1==-1) return p1;
    return join(p1, p2);
}

void update(int node, int b, int e, int i, int j, int v) {
    if(M[node].lazy) {
        if(b!=e) {
            M[2*node].lazy+=M[node].lazy;
            M[2*node+1].lazy+=M[node].lazy;
        }
		if((M[node].lazy)&1) {
			swap(M[node].a1, M[node].b2);
			swap(M[node].b1, M[node].a2);
		}
        M[node].lazy=0;
    }
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
		swap(M[node].a1, M[node].b2);
		swap(M[node].b1, M[node].a2);
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
	int n, q;
	scanf("%d %d", &n, &q);
	scanf("%s", s);
	init(1, 0, n-1);
	for(int i=0; i<q; i++) {
		int op, l, r, a, b;
		scanf("%d %d %d", &op, &l, &r);
		l--, r--;
		if(op==1) update(1, 0, n-1, l, r, 1);
		else {
			scanf("%d %d", &a, &b);
			interval iq=query(1, 0, n-1, l, r);
			printf("%lld %lld\n", ((iq.a1*a)%MOD+(iq.b1*b)%MOD)%MOD, ((iq.a2*a)%MOD+(iq.b2*b)%MOD)%MOD);
		}
	}
	return 0;
}
