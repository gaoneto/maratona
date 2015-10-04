#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define INF 1000000000
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N=22;
char sp[N][4*N], sq[N][4*N];
//cnt[line][r/c/s][open/close][text p/q]
int cnt[N][3][2][2], cp[N];

void add(int i, int t, char c) {
    if(c=='(') cnt[i][0][0][t]++;
    if(c==')') cnt[i][0][1][t]++;
    if(c=='{') cnt[i][1][0][t]++;
    if(c=='}') cnt[i][1][1][t]++;
    if(c=='[') cnt[i][2][0][t]++;
    if(c==']') cnt[i][2][1][t]++;
}

int main() {
    int p, q;
    while(scanf("%d %d", &p, &q) && (p || q)) {
        memset(cnt, 0, sizeof(cnt));
        memset(cp, 0, sizeof(cp));
        for(int i=1; i<=p; i++) {
            scanf("%s", sp[i]);
            for(int j=0; j<3; j++) for(int k=0; k<2; k++) cnt[i][j][k][0]=cnt[i-1][j][k][0];
            for(int j=0; sp[i][j]; j++) add(i, 0, sp[i][j]);
            for(int j=0; sp[i][j]=='.'; j++) cp[i]++;
        }
        for(int i=1; i<=q; i++) {
            scanf("%s", sq[i]);
            for(int j=0; j<3; j++) for(int k=0; k<2; k++) cnt[i][j][k][1]=cnt[i-1][j][k][1];
            for(int j=0; sq[i][j]; j++) add(i, 1, sq[i][j]);
        }
        vector<piii> pos;
        vector<int> ans;
        for(int r=1; r<=MAX; r++) for(int c=1; c<=MAX; c++) for(int s=1; s<=MAX; s++) {
            int f=1;
            for(int i=1; i<=p; i++) {
                int tot=r*(cnt[i-1][0][0][0]-cnt[i-1][0][1][0])+
                        c*(cnt[i-1][1][0][0]-cnt[i-1][1][1][0])+
                        s*(cnt[i-1][2][0][0]-cnt[i-1][2][1][0]);
                if(tot!=cp[i]) {
                    f=0;
                    break;
                }
            }
            if(f) pos.push_back(piii(r, pii(c, s)));
        }
        for(int i=1; i<=q; i++) {
            int val=-INF;
            for(int j=0; j<pos.size(); j++) {
                int r=pos[j].first;
                int c=pos[j].second.first;
                int s=pos[j].second.second;
                int tot=r*(cnt[i-1][0][0][1]-cnt[i-1][0][1][1])+
                        c*(cnt[i-1][1][0][1]-cnt[i-1][1][1][1])+
                        s*(cnt[i-1][2][0][1]-cnt[i-1][2][1][1]);
                if(val==-INF) val=tot;
                else if(val!=tot) {
                    val=-INF;
                    break;
                }
            }
            if(val==-INF) ans.push_back(-1);
            else ans.push_back(val);
        }
        printf("%d", ans[0]);
        for(int i=1; i<ans.size(); i++) printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
