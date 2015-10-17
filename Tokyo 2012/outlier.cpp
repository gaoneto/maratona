#include <bits/stdc++.h>
#define EPS 1e-3
using namespace std;

const int N=11;
int n, d;
double m[N][N], aux[N][N], coef[N][N], sol[N], dp[2][N][N][N];

//Mahajan and Vinay Dynamic Algorithm
double Determinant() {
    int p, u, v, w, b=n%2, i;
    double x[2]={0, 0};
    for(p=0; p<2; p++) for(u=0; u<n; u++) for(v=0; v<n; v++) for(w=0; w<n; w++) dp[p][u][v][w]=0;
    for(u=0; u<n; u++) dp[b][u][u][0]=1;
    for(i=0; i<=n-2; i++) for(u=0; u<n; u++) for(v=u; v<n; v++) for(p=0; p<2; p++) for(w=u+1; w<n; w++) {
        dp[p][u][w][i+1]+=dp[p][u][v][i]*m[v][w];
        dp[1-p][w][w][i+1]+=dp[p][u][v][i]*m[v][u];
    }
    for(u=0; u<n; u++) for(v=u; v<n; v++) {
        x[0]+=dp[1][u][v][n-1]*m[v][u];
        x[1]+=dp[0][u][v][n-1]*m[v][u];
    }
    return x[0]-x[1];
}

int check(int l) {
    int vis[N];
    memset(vis, 0, sizeof(vis));
    n=0;
    for(int i=0; i<d+3 && n!=d+1; i++) if(i!=l) vis[i]=1, n++;
    n=0;
    for(int i=0; i<d+3; i++) if(vis[i]) {
        for(int j=0; j<d+1; j++) coef[n][j]=aux[i][j];
        n++;
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) m[i][j]=coef[i][j];
    double ret=Determinant();
    if(fabs(ret)<EPS) return 0;
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) m[i][j]=coef[i][j];
        int cnt=0;
        for(int j=0; j<d+3; j++) if(vis[j]) m[cnt++][k]=aux[j][d+1];
        sol[k]=Determinant()/ret;
    }
    int f=0;
    for(int i=0; i<d+3; i++) if(!vis[i]) {
        double p=1, val=0;
        if(i==l) {
            for(int j=d; j>=0; j--, p*=i) val+=p*sol[j];
            if(fabs(val-aux[i][d+1])>0.9) f++;
        }
        else {
            for(int j=d; j>=0; j--, p*=i) val+=p*sol[j];
            if(fabs(val-aux[i][d+1])<EPS) f++;
        }
    }
    return (f==2);
}

int solve() {
    for(int i=0; i<d+3; i++) if(check(i)) return i;
    return -1;
}

int main() {
    while(scanf("%d", &d) && d) {
        for(int i=0; i<d+3; i++) {
            scanf("%lf", &aux[i][d+1]);
            double p=1;
            for(int j=d; j>=0; j--, p*=i) aux[i][j]=p;
        }
        printf("%d\n", solve());
    }
    return 0;
}
