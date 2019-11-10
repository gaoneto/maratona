#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
    
int n, p, nc, h;

const int N=1e6+10;
int c[N], m[N], w[N], sc[N], sm[N];

int valid(int a, int b) {
    if(a==-1 || a==h) return 1;

    sc[c[b]]--;
    sc[m[0]]++;

    int sa = min(sc[a] + sm[a], n-1);
    if(m[p-1] == a) sa++;

    int sh = sc[h];
    if(sh >= 1) sh--;
    sh = max(0, sh - (p-2 - sm[h]));
    if(m[p-1] == h) sh++;

    sc[m[0]]--;
    sc[c[b]]++;

    //cerr<<sh<<" "<<sa<<endl;

    if(sh > sa) return 1;
    return 0;
}

int main() {
    freopen("kabaleo.in", "r", stdin);
    freopen("kabaleo.out", "w", stdout);
    cin>>n>>p>>nc>>h;
    for(int i=0;i<n;i++) {
        scanf("%d", &c[i]);
        sc[c[i]]++;
    }
    for(int i=0;i<p;i++) {
        scanf("%d", &m[i]);
        if(i!=0 && i!=p-1) sm[m[i]]++;
    }
    int cor[] = {m[p-1], m[0], 0, 0};
    int best1, best2, val=0;
    priority_queue<pii> q;
    for(int i=0;i<nc;i++) q.push(pii(sm[i] + sc[i], i));
    if(!q.empty()) cor[2] = q.top().second;
    else cor[2] = -1;
    if(!q.empty()) {
        q.pop();
        if(!q.empty()) cor[3] = q.top().second;
        else cor[3] = -1;
    }
    //cerr<<cor[0]<<" "<<cor[1]<<" "<<cor[2]<<endl;
    for(int i=0;i<n;i++) w[i] = valid(cor[0], i) && valid(cor[1], i) && valid(cor[2], i) && valid(cor[3], i);
    int sum=0;
    for(int i=0;i<n;i++) if(w[i]) sum++;
    cout<<sum<<endl;
    //for(int i=0;i<n;i++) cerr<<w[i]<<" ";cerr<<endl; 
    //cerr<<sum<<endl;
    for(int i=0;i<n;i++) if(w[i]) {
        printf("%d\n", i+1);
        //cerr<<i+1<<endl;
    }
    return 0;
}
