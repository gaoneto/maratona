#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int pi[111111], rank[111111];

int FindSet(int x) { return (pi[x]==x) ? x : pi[x]=FindSet(pi[x]); }

void Union(int x, int y) {
	x=FindSet(x);
	y=FindSet(y);
	if(x==y) return;
	if(rank[x]>rank[y]) pi[y]=x;
	else {
		pi[x]=y;
		if(rank[x]==rank[y]) rank[y]++;
	}
}

int main() {
    int n, k, p, a;
    scanf("%d %d %d", &n, &k, &p);
	for(int i=0; i<n; i++) {
		scanf("%d", &a);
		pi[i]=i;
		v.push_back(make_pair(a, i));
	}
	sort(v.begin(), v.end());
	for(int i=1; i<n; i++) if(v[i].first-v[i-1].first<=k) Union(v[i].second, v[i-1].second);
	for(int i=0; i<p; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		printf("%s\n", FindSet(x)==FindSet(y) ? "Yes" : "No");
	}
    return 0;
}
