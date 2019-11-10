#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int t=1;
	long long n;
	while(scanf("%lld", &n) && n)
	{
		printf("Case %d: ", t++);
		if(n&1) printf("0\n");
		else
		{
			n=(n-4)/2;
			long long ans=(n+5)*(n+4)*(n+3)*(n+2)*(n+1)/120;
			if(n>1) ans-=(n+3)*(n+2)*(n+1)*n*(n-1)/120;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
