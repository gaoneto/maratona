#include <bits/stdc++.h>

using namespace std;

int tab[555][555];
int vis[555][555];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int mc, mr;
char trans[] = {'W', 'A', 'K', 'J', 'S', 'D'};

int to_int(char c) {
    if(c <= '9' && c >= '0') return c-'0';
    else return c-'a'+10;
}

void gen(string s, int r) {
    int k = 1;
    for(int i=0;i<s.size();i++) {
        int v = to_int(s[i]);
        for(int i=0;i<4;i++) {
            if(v&(1<<(3-i))) tab[r][k] = 1;
            k++;
        }
    }
}

void flood(int r, int c, int v) {
    queue <pair<int,int> > q;
    q.push(make_pair(r,c));
    tab[r][c] = v;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr < 0 || nc < 0 || nr > mr || nc > mc) continue;
            if(tab[nr][nc] == 0) {
                tab[nr][nc] = v;
                q.push(make_pair(nr,nc));
            }
        }
    }
}

char solve(int r, int c) {
    int cc = 0;
    queue <pair<int,int> > q;
    q.push(make_pair(r,c));
    tab[r][c] = 2;
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr < 0 || nc < 0 || nr > mr || nc > mc) continue;
            if(tab[nr][nc] == 1) {
                tab[nr][nc] = 2;
                q.push(make_pair(nr,nc));
            }
            if(tab[nr][nc] == 0) {
                flood(nr,nc,3);
                cc++;
            }
        }
    }
    return trans[cc];
}

int main() {
    int h, w;
    string s;
    int T = 1;
    while(scanf("%d %d", &h, &w) && h) {
        mc = 4*w + 1;
        mr = h+1;
        memset(tab,0,sizeof(tab));
        for(int i=1;i<=h;i++) {
            cin >> s;
            gen(s,i);
        }
        flood(0,0,-1);
        string ret = "";
        for(int i=1;i<=4*w;i++) {
            for(int j=0;j<=h;j++) {
                if(tab[j][i] == 1) ret += solve(j,i);
            }
        }
        printf("Case %d: ", T++);
        sort(ret.begin(), ret.end());
        cout << ret << endl;
    }
    return 0;
}
