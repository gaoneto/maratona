#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y) {
	if(!y) return (x&1) ? 2*x+1 : 2*x;
	return (y&1) ? 2*y-1 : 2*y;
}

int main() {
    int t, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &x, &y);
		if(x<0) x=-x;
		if(y<0) y=-y;
		printf("%d\n", 2*min(x, y)+solve(x-min(x, y), y-min(x, y)));
    }
    return 0;
}
