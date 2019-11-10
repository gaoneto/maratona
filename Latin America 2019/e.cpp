#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
string b;
int nxt[N];

int main() {
	int s, n;
	long long ans=0;
	cin >> b >> s;
	b+=b;
	n=(int)b.size();
	nxt[n]=n;
	for(int i=n-1; i>=0; i--) {
		nxt[i]=nxt[i+1];
		if(b[i]=='E') nxt[i]=i;
	}
	for(int i=0; 2*i<n; i++) {
		if(b[i]=='E') ans+=s;
		else ans+=max(0, i+s-nxt[i]);
	}
	cout << ans << endl;
	return 0;
}
