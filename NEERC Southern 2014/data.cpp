#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s[222222];

int main() {
	int n, l, r, t=1e9;
	vector<pair<ll, int> > a[2];
	ll x, m, sum=0;
	scanf("%d %I64d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%I64d %d", &x, &l);
		a[l].push_back(make_pair(x, i+1));
	}
	for(int i=0; i<2; i++) sort(a[i].begin(), a[i].end(), greater<pair<ll, int> >());
	n=(int)a[0].size(), l=-1;
	for(int i=0; i<n; i++) s[i+1]=s[i]+a[0][i].first;
	for(int i=-1; i<(int)a[1].size(); i++) {
		if(i>=0) sum+=a[1][i].first;
		int p0=lower_bound(s, s+n+1, m-sum)-s, p1=i+1;
		if(p0<=n && (p0+p1<t || (p0+p1==t && p1>l))) t=p0+p1, r=p0, l=p1;
	}
	printf("%d %d\n", t, l);
	for(int i=0; i<r; i++) printf("%d ", a[0][i].second);
	for(int i=0; i<l; i++) printf("%d ", a[1][i].second);
	printf("\n");
	return 0;
}
