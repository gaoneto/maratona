#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define ff first
#define ss second

const int N=1e2+10;
int n, m, d[N][N], empty[N], r[N][N];
vector<piii> v[5];

void transitive_closure() {
	for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++) d[i][j]=d[i][j] | (d[i][k] & d[k][j]);
}

int valid(int val) {
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) d[i][j]=r[i][j]=0;
	for(int i=0; i<n; i++) empty[i]=0, d[i][i]=1;
	for(int i=0; i<v[0].size() && v[0][i].ff<val; i++) d[v[0][i].ss.ff][v[0][i].ss.ss]=1;
	for(int i=0; i<v[1].size() && v[1][i].ff<val; i++) d[v[1][i].ss.ff][v[1][i].ss.ss]=d[v[1][i].ss.ss][v[1][i].ss.ff]=1;
	transitive_closure();
	for(int i=0; i<v[3].size() && v[3][i].ff<val; i++) {
		r[v[3][i].ss.ff][v[3][i].ss.ss]=1;
		for(int j=0; j<n; j++) if(d[j][v[3][i].ss.ff] && d[j][v[3][i].ss.ss]) empty[j]=1;
	}
	for(int i=0; i<v[2].size() && v[2][i].ff<val; i++) if((d[v[2][i].ss.ff][v[2][i].ss.ss] && d[v[2][i].ss.ss][v[2][i].ss.ff]) || (empty[v[2][i].ss.ff] && empty[v[2][i].ss.ss])) return 0;
	for(int i=0; i<v[4].size() && v[4][i].ff<val; i++) {
		if(r[v[4][i].ss.ff][v[4][i].ss.ss] || empty[v[4][i].ss.ff] || empty[v[4][i].ss.ss]) return 0;
		for(int j=0; j<n; j++) if(d[v[4][i].ss.ff][j]) for(int k=0; k<n; k++) if(d[v[4][i].ss.ss][k] && r[min(j, k)][max(j, k)]) return 0;
	}
	return 1;
}

int main() {
	while(scanf("%d %d", &n, &m) && (n || m)) {
		int lo=1, mid, hi=m+1;
		for(int i=0; i<5; i++) v[i].clear();
		for(int i=0; i<m; i++) {
			int s, a, b;
			scanf("%d %d %d", &s, &a, &b);
			s--, a--, b--;
			if(s && a>b) swap(a, b);
			v[s].push_back(piii(i, pii(a, b)));
		}
		while(lo<hi) {
			mid=(lo+hi)/2;
			if(valid(mid)) lo=mid+1;
			else hi=mid;
		}
		printf("%d\n", lo-1);
	}
	return 0;
}
