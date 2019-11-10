#include <bits/stdc++.h>
using namespace std;

int a[111111];

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		long long ans=0;
		for(int i=n-1; i>=0; i-=2) ans+=a[i];
		printf("%lld\n", ans);
	}
	return 0;
}
