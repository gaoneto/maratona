#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, t, n, x, y, a[111];
    scanf("%d", &t);
    while(t--) {
		scanf("%d %d %d", &n, &x, &y);
		for(int i=1; i<=n; i++) scanf("%d", &a[i]);
		if(a[1]==x && a[n]==y) printf("BOTH\n");
		else if(a[1]==x) printf("EASY\n");
		else if(a[n]==y) printf("HARD\n");
		else printf("OKAY\n");
    }
    return 0;
}
