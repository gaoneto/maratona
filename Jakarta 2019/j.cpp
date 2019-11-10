#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5+10;
int dp[N][55];
string s;
 
int main() {
	int n, k, g1, g2, g3, cnt=0, cdot=0, ans=0;
	scanf("%d %d %d %d %d", &n, &k, &g1, &g2, &g3);
	cin >> s;
	s=" "+s+"   ";
	memset(dp, -1, sizeof(dp));
	dp[0][0]=0;
	for(int i=0; i<=n; i++) {
		if(s[i]=='.') cdot++;
		if(s[i]=='.' && s[i+1]=='#' && s[i+2]=='.') cnt++;
		for(int j=0; j<=cnt; j++) if(dp[i][j]!=-1) {
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
			if(s[i+1]=='.' && s[i+2]=='.') dp[i+2][j]=max(dp[i+2][j], dp[i][j]+1);
			if(s[i+1]=='.' && s[i+2]=='#' && s[i+3]=='.') dp[i+3][j+1]=max(dp[i+3][j+1], dp[i][j]);
		}
	}
	for(int i=0; i<=cnt; i++) {
		int q1, q2, q3, tot, aux=k;
		q3=i;
		q2=dp[n][i];
		q1=cdot-2*q3-2*q2;
		tot=min(aux, q1)*g1+q2*g2+q3*g3;
		aux-=min(aux, q1);
		if(2*g1>g2 && aux>1) {
    		int aux2=min(aux/2, q2);
			tot+=(2*aux2*g1-aux2*g2);
			aux-=2*aux2;
      		q2-=aux2;
		}
		if(g1>g2 && aux==1 && q2>0) tot+=(g1-g2);
		ans=max(ans, tot);
	}
	printf("%d\n", ans);
	return 0;
}
