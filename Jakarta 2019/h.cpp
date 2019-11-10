#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > b;

int main() {
	int n, l, w;
	long long ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &l, &w);
		if(l>w) swap(l, w);
		b.push_back(make_pair(l, w));
		ans=max(ans, 1ll*l*w);
	}
	sort(b.begin(), b.end());
	int w_max=b[n-1].second;
	for(int i=n-2; i>=0; i--) {
		ans=max(ans, 2ll*b[i].first*min(b[i].second, w_max));
		w_max=max(w_max, b[i].second);
	}
	printf("%lld.%d\n", ans/2, (ans&1)?5:0);
	return 0;
}
