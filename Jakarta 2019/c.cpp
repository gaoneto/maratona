#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int erow[N], ecol[N], orow[N], ocol[N];

int main() {
	int n, q, r, c;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; i++) {
		scanf("%d", &r);
		orow[i]=orow[i-1];
		erow[i]=erow[i-1];
		if(r&1) orow[i]++;
		else erow[i]++;
	}
	for(int i=1; i<=n; i++) {
		scanf("%d", &c);
		ocol[i]=ocol[i-1];
		ecol[i]=ecol[i-1];
		if(c&1) ocol[i]++;
		else ecol[i]++;
	}
	for(int i=0; i<q; i++) {
		int ra, ca, rb, cb;
		scanf("%d %d %d %d", &ra, &ca, &rb, &cb);
		if(ra>rb) swap(ra, rb);
		if(ca>cb) swap(ca, cb);
		if((erow[rb]-erow[ra-1])==(rb-ra+1) && (ecol[cb]-ecol[ca-1])==(cb-ca+1)) printf("YES\n");
		else if((orow[rb]-orow[ra-1])==(rb-ra+1) && (ocol[cb]-ocol[ca-1])==(cb-ca+1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
