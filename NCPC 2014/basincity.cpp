#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> adj[N];

int isadj(int a, int b) {
	for(int i=0;i<adj[a].size();i++) if(adj[a][i] == b) return 1;
	return 0;
}
	
int n, k;

int getrand() {
	int tam = 1<<16;
	int ret = ((rand() & (tam-1)) + ((rand() & (tam-1))>>16))%n;
	return ret;
}

int main() {
	srand(time(NULL));
	cin>>k>>n;
	if(k > n) {
		cout << "impossible" << endl;
		return 0;
	}
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d", &x);
		for(int i=0;i<x;i++) {
			int j;
			scanf("%d", &j); j--;
			if(!isadj(j, i)) adj[i].push_back(j);
		}
	}
	int pos[16];
	for(int t=1;t<=500000;t++) {
		for(int i=0;i<k;i++) pos[i]=getrand();
		int ok=1;
		for(int i=0;i<k;i++) for(int j=i+1;j<k;j++) if(!ok || pos[i] == pos[j] || isadj(pos[i], pos[j]) || isadj(pos[j], pos[i])) ok=0;
		if(ok) {
			cout << "possible" << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
	return 0;
}
