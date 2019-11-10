#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N=1001;
int win[N][N], m[N][N], ans[N], can[N][N];
		
int nlose[N];
ull vwin[N][20], vlose[N][20];

int main() {
	int n;
	while(scanf("%d", &n)!=EOF) {
		memset(win, 0, sizeof(win));
		memset(m, 0, sizeof(m));
		memset(vwin, 0ull, sizeof(vwin));
		memset(vlose, 0ull, sizeof(vlose));
		memset(nlose, 0, sizeof(nlose));
		memset(can, 0, sizeof(can));
        for(int i=0; i<n; i++) {
			int d;
			scanf("%d", &d);
			for(int j=0; j<d; j++) {
				int x;
				scanf("%d", &x);
				x--;
                nlose[x]++;
                win[i][x]=1;
                vwin[i][x/64] |= 1ull<<(x%64);
                vlose[x][i/64] |= 1ull<<(i%64);
			}
		}
        int good=1;
        ull aux[N][20];
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
            int k;
            for(k=0;k<20;k++) if((vwin[i][k] & vlose[j][k]) != 0ull) break;
            if(k != 20) m[i][j]=1;
            for(k=0;k<20;k++) if((vwin[j][k] & vlose[i][k]) != 0ull) break;
            if(k != 20) m[j][i]=1;
            can[i][j] = m[i][j] | win[i][j];
            can[j][i] = m[j][i] | win[j][i];
            if(!can[i][j] && !can[j][i]) {
                //printf("%d %d\n", i, j);
                good=0;
            }
        }
        if(!good) {
            printf("inclassificavel\n");
        }
        else {
            vector<int> ans;
            for(int i=0;i<n;i++) {
                int k;
                for(k=-1 + (int)ans.size(); k>=0;k--) {
                    if(!can[i][ans[k]]) {
                        ans.insert(ans.begin() + k + 1, i);
                        break;
                    }
                }
                if(k==-1) {
                    ans.insert(ans.begin(), i);
                }
            }
            printf("%d", ans[0]+1);
            for(int i=1; i<n; i++) printf(" %d", ans[i]+1);
            printf("\n");
        }
	}
	return 0;
}
