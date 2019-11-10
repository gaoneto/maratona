#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N];

int main() {
	int n, x, ans=1;
	scanf("%d %d", &n, &x);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<n; i++) {
		int j=i;
		for(j=i+1; j<n && a[j]-a[j-1]<=x; j++);
		ans=max(ans, j-i);
	}
	printf("%d\n", ans);
	return 0;
}
