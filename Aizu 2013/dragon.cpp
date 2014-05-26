#include <bits/stdc++.h>

using namespace std;

int dp[444444];
int fat[11], pot[11], pend;
pair<int,int> adj[444444][5];
char vis[444444];
string start, end;
int c[2];
const int INF=1e9;

int perm(string s) {
    int ret=0;
    for(int i=0;i<9;i++) {
        int cnt=0;
        for(int j=i+1; j<9; j++) if(s[j]<s[i]) cnt++;
        ret+=fat[8-i]*cnt;
    }
    return ret;
}

void go(string s) {
    priority_queue <pair<int,int> > q;
    q.push(make_pair(0,perm(s)));
    dp[perm(s)] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        if(vis[pend]) return;
        for(int i=0;i<4;i++) {
            int v = adj[u][i].first;
            if(dp[v] > dp[u]+c[adj[u][i].second]) {
                dp[v] = dp[u]+c[adj[u][i].second];
                q.push(make_pair(-dp[v],v));
            }
        }
    }
}

int main() {
    char cc;
    fat[0]=1;
    pot[0]=1;
    string s="0";
    for(int i=1; i<9; i++) {
        fat[i]=fat[i-1]*i;
        pot[i] = pot[i-1]*9;
        s += ('0'+i);
    }
    fat[9] = fat[8]*9;
    int t = 0;
    do {
        int l;
        for(int i=0;i<9;i++) if(s[i] == '0') l = i;
        int nl = (l+3)%9;
        swap(s[l],s[nl]);
        adj[t][0] = make_pair(perm(s),1);
        swap(s[l],s[nl]);
        nl = (l+6)%9;
        swap(s[l],s[nl]);
        adj[t][1] = make_pair(perm(s),1);
        swap(s[l],s[nl]);
        nl = (l+1)%9;
        swap(s[l],s[nl]);
        adj[t][2] = make_pair(perm(s),0);
        swap(s[l],s[nl]);
        nl = (l+8)%9;
        swap(s[l],s[nl]);
        adj[t][3] = make_pair(perm(s),0);
        swap(s[l],s[nl]);
        t++;
    } while(next_permutation(s.begin(),s.end()));

    while(cin >> c[0] >> c[1] && c[0] && c[1]) {
        for(int i=0; i<fat[9]; i++) vis[i]=0, dp[i]=INF;
        start = "";
        end = "";
        for(int i=0;i<9;i++) {
            cin >> cc;
            start += cc;
        }
        for(int i=0;i<9;i++) {
            cin >> cc;
            end += cc;
        }
        pend=perm(end);
        go(start);
        cout << dp[pend] << endl;
    }
    return 0;
}
