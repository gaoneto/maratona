#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main() {
	int t=0, j, n, a[22], w=-1;
	deque<char> d[22];
	stack<char> s[22];
	freopen("jungle.in", "r", stdin);
	freopen("jungle.out", "w", stdout);
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<n; i++) {
		char c[111];
		scanf("%s", c);
		for(int j=0; c[j]; j++) d[i].push_back(c[j]);
	}
	for(int p=0; t<=MAX && w==-1; p=(p+1)%n) if(!d[p].empty()) {
		t++;
		char c=d[p].front();
		d[p].pop_front();
		s[p].push(c);
		for(j=0; j<n; j++) if(j!=p && !s[j].empty() && s[j].top()==c) {
			int x=p, y=j;
			if(a[x]>=a[y]) swap(x, y);
			while(!s[y].empty()) {
				d[y].push_back(s[y].top());
				s[y].pop();
			}
			while(!s[x].empty()) {
				d[y].push_back(s[x].top());
				s[x].pop();
			}
		}
		for(j=0; j<n; j++) if(s[j].empty() && d[j].empty()) {
			w=j;
			break;
		}
		for(j=0; j<n; j++) if(!d[j].empty()) break;
		if(j==n) break;
	}
	if(w!=-1) printf("Player %d wins after %d moves.\n", w+1, t);
	else if(t>MAX) printf("Abandoned after %d moves.\n", MAX);
	else printf("Draw after %d moves.\n", t);
	return 0;
}
