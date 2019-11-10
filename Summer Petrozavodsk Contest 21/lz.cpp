#include <bits/stdc++.h>
using namespace std;

string t, p, ret;
vector<int> match;
int pi[4444], ans;

void prefix() {
	int m, q, k;
	m=p.size();
	pi[0]=0;
	k=0;
	for(q=1; q<m; ++q) {
		while(k>0 && p[k]!=p[q]) k=pi[k-1];
		if(p[k]==p[q]) ++k;
		pi[q]=k;
	}
}

pair<int, int> kmp(int pos) {
	int n=t.size(), q=0, m = p.size();
	pair <int,int> r = make_pair(0,0);
	for(int i=0; i<n; i++) {
		if(i-q >= pos) return r;
		while(q>0 && p[q]!=t[i]) {
			if(q > r.second) r = make_pair(pos-(i-q),q);
			q=pi[q-1];
		}
		if(p[q]==t[i]) ++q;
		if(q == m) {
			r = make_pair(pos-(i-q+1),q);
			return r;
		}
	}
	return r;
}

string to_str(int x) {
	char buf[111];
	sprintf(buf, "%d", x);
	return string(buf);
}

void solve(int pos) {
	if(pos==t.size()) return;
	p = t.substr(pos);
	prefix();
	pair<int, int> k=kmp(pos);
	if(k.second<3) {
		ans+=9;
		ret+=t[pos];
		solve(pos+1);
	}
	else {
		ans+=25;
		ret+="("+to_str(k.first)+","+to_str(k.second)+")";
		solve(pos+k.second);
	}
}

int main() {
	freopen("lz.in", "r", stdin);
	freopen("lz.out", "w", stdout);
	cin >> t;
	prefix();
	ans=9;
	ret = "";
	ret+=t[0];
	solve(1);
	printf("%d\n%s\n", ans, ret.c_str());
	return 0;
}
