#include <bits/stdc++.h>

using namespace std;

unsigned a[10001][10001];

int main() {
	int n, m;
	unsigned x, y;
	char c1, c2, c3, c4;
	int i = 0;
	while(1) {
		c1 = getchar();
		if(c1 == -1) break;
		c2 = getchar();
		c3 = getchar();
		c4 = getchar();
		unsigned u1 = (c1%(1u<<8)), u2 = (c2%(1u<<8)), u3 = (c3%(1u<<8)), u4 = (c4%(1u<<8));
		//printf("%u%u%u%u\n", u1,u2,u3,u4);
		unsigned c = (((unsigned)u4)<<24)+(((unsigned)u3)<<16)+(((unsigned)u2)<<8)+(unsigned)u1;
		//cout << "#" << c << endl;
		if(i == 0) n = c;
		else if(i == 1) m = c;
		else if(i <= (n*m)+1) {
			int k = i-2;
			a[k/m][k%m] = c;
		}
		else if(i > (n*m)+1) {
			int k = i - 2 - n*m;
			if(k%2 == 0) x = c;
			else {
				y = c;
				int r = 0;
				for(int i=0;i<n;i++) {
					int f = lower_bound(a[i],a[i]+m,x) - a[i];
					int l = upper_bound(a[i],a[i]+m,y) - a[i];
					r += l - f;
				}
				printf("%d\n", r);
			}
		}
		i++;
	}
	return 0;
}
