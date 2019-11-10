#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

map<string, int> ms;
int tam[222];

void cut(string &s, string &a, string sep) {
	int eq = s.find(sep);
	a = s.substr(0, eq);
	s = s.substr(eq+1);
}

int n=0;

struct Pattern {
	int tam;
	int inner;
	vector<int> up, down, left, right;
};

Pattern p[222];

int id(string s) {
	if(ms.count(s)) return ms[s];
	if(s=="0" || s=="1") {
		p[n].tam=1;
		p[n].inner=0;
		p[n].up.push_back(s[0]-'0');
		p[n].down.push_back(s[0]-'0');
		p[n].left.push_back(s[0]-'0');
		p[n].right.push_back(s[0]-'0');
	}
	return ms[s]=n++;
}

int par[16*(1<<16)+11];

int findpar(int x) {
	return par[par[x]] == par[x] ? par[x] : par[x] = findpar(par[x]);
}

void increase(int &ans, vector<int> &v, set<int> &s, int start=0, int find=0) {
	for(int i=0;i<v.size();i++) if(v[i] != 0) {
		int x = v[i]+start;
		if(find) x = findpar(x);
		if(s.count(x)) continue;
		s.insert(x);
		ans++;
	}
}

void resetvector(int pa, int start, int t) {
	if(p[pa].up[0])	par[findpar(start+p[pa].up[0])] = findpar(start+p[pa].left[0]+3*t);
	if(p[pa].up.back())	par[findpar(start+p[pa].up.back())] = findpar(start+p[pa].right[0]+t);
	if(p[pa].down[0])	par[findpar(start+p[pa].down[0]+2*t)] = findpar(start+p[pa].left.back()+3*t);
	if(p[pa].down.back())	par[findpar(start+p[pa].down.back()+2*t)] = findpar(start+p[pa].right.back()+t);
}

void reset(int init, int val) { 
	if(val != 0) val += init;
	par[val]=val; 
}
void reset(int pa, int i, int init, int delta) {
	reset(init, p[pa].up[i]);
	reset(init + delta, p[pa].right[i]);
	reset(init + 2*delta, p[pa].down[i]);
	reset(init + 3*delta, p[pa].left[i]);
}

void merge(vector<int> &a, int sa, vector<int> &b, int sb) {
	for(int i=0;i<a.size();i++) {
		if(a[i]==0 || b[i]==0) continue;
		int x = findpar(a[i]+sa);
		int y = findpar(b[i]+sb);
		if(x==y) continue;
		par[x]=y;
	}
}

void transfer(vector<int>&a, vector<int>&b, int start) {
	for(int i=0;i<b.size();i++) {
		if(!b[i]) a.push_back(0);
		else a.push_back(findpar(b[i]+start));
	}
}

int main() {
	freopen("map.in", "r", stdin);
	//freopen("map.out", "w", stdout);
	while(1) {
		string s, ps, as, bs, cs, ds;
		cin>>s;
		cut(s, ps, "=");
		cut(s, as, ",");
		cut(s, bs, ",");
		cut(s, cs, ",");
		cut(s, ds, ",");
		int pp = id(ps);
		int pa = id(as);
		int pb = id(bs);
		int pc = id(cs);
		int pd = id(ds);
		p[pp].inner = p[pa].inner + p[pb].inner + p[pc].inner + p[pd].inner;
		int t = p[pa].tam;
		p[pp].tam = 2*t;
		for(int i=0;i<t;i++) {
			reset(pa, i, t, t);
			reset(pb, i, 4*t, t);
			reset(pc, i, 8*t, t);
			reset(pd, i, 12*t, t);
		}
		for(int i=0;i<t;i++) {
			merge(p[pa].right, t, p[pb].left, 7*t);	
			merge(p[pa].down, 2*t, p[pc].up, 8*t);
			merge(p[pb].down, 6*t, p[pd].up, 12*t);
			merge(p[pc].right, 9*t, p[pd].left, 15*t);
		}
		resetvector(pa, 0, t);
		resetvector(pb, 4*t, t);
		resetvector(pc, 8*t, t);
		resetvector(pd, 12*t, t);

		transfer(p[pp].up, p[pa].up, 0);
		transfer(p[pp].up, p[pb].up, 4*t);
		
		transfer(p[pp].right, p[pb].right, 5*t);
		transfer(p[pp].right, p[pd].right, 13*t);
		
		transfer(p[pp].down, p[pc].down, 10*t);
		transfer(p[pp].down, p[pd].down, 14*t);
		
		transfer(p[pp].left, p[pa].left, 3*t);
		transfer(p[pp].left, p[pc].left, 11*t);

		set<int> vis;
		int aux=0;
		increase(aux, p[pp].up, vis);
		increase(aux, p[pp].left, vis);
		increase(aux, p[pp].right, vis);
		increase(aux, p[pp].down, vis);

		increase(p[pp].inner, p[pa].right, vis, t, 1);
		increase(p[pp].inner, p[pa].down, vis, 2*t, 1);

		increase(p[pp].inner, p[pb].down, vis, 6*t, 1);
		increase(p[pp].inner, p[pb].left, vis, 7*t, 1);

		increase(p[pp].inner, p[pc].up, vis, 8*t, 1);
		increase(p[pp].inner, p[pc].right, vis, 9*t, 1);

		increase(p[pp].inner, p[pd].up, vis, 12*t, 1);
		increase(p[pp].inner, p[pd].left, vis, 15*t, 1);

		if(ps == "Map") {
			set<int> vis;
			int ans = p[pp].inner;
			increase(ans, p[pp].up, vis);
			increase(ans, p[pp].down, vis);
			increase(ans, p[pp].left, vis);
			increase(ans, p[pp].right, vis);
			cout << ans << endl;
			return 0;
		}
	}
}
