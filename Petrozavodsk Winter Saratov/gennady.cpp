#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v;

const int N = 1e6+1;
ll dp[N];

int main() {
	int n, t;
	cin>>n>>t;
	ll ans=t;
	ll a1=1;
	int r=2;
	for(int i=1;i<=n;i++) {
		if(a1 <= t+1) {
			ans += a1;
			a1 += r;
		}
		else {
			ans += 1+t;
			r++;
			a1 = 1+r;
			v.push_back(i-1);
		}
		dp[i] = ans;
	}
	ll best = (1ll+n)*n/2;
	int pos=-1;
	for(int i=1;i<n;i++) {
		ll aux = (1ll+i)*i/2 + dp[n-i];
		if(best > aux) {
			best = aux;
			pos = i;
		}
	}
	vector<int> u;
	cout << best << endl;
	if(pos != -1) {
		u.push_back(pos);
		for(int i=0;i<v.size();i++) {
			v[i] += pos;
			if(v[i] < n) u.push_back(v[i]);
		}
	}
	cout << u.size() << endl;
	if(u.size()) {
		cout << u[0];
		for(int i=1;i<u.size();i++) cout << " " << u[i];
		cout << endl;
	}
	return 0;
}
