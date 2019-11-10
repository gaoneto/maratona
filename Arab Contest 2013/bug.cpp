#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x, y;
    scanf("%d", &t);
    while(t--) {
		scanf("%d %d %d", &n, &x, &y);
		int cnt=0, f=0;
		for(int i=1; cnt<n; i++) {
			if(cnt<n-1) {
				if(y==1 && x==i) continue;
				if(f) printf(" ");
				printf("%d", i);
				cnt++, f=1;
			}
			else {
				if(y==1 && x==i) continue;
				if(y==2 && i<x) continue;
				if(f) printf(" ");
				printf("%d", i);
				cnt++;
			}
		}
		printf("\n");
    }
    return 0;
}
