#include <bits/stdc++.h>
using namespace std;

int n, aux[33][33], x[33][33], y[33][33];

void rotate() {
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) aux[j][n-i-1] = x[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) x[i][j] = aux[i][j];
}

int main() {
    while(cin >> n && n) {
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>x[i][j];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>y[i][j];
        int ans = 0;
        for(int k=0;k<4;k++) {
            rotate();
            int aux=0;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(x[i][j] == y[i][j]) aux++;
            ans = max(ans, aux);
        }
        cout << ans << endl;
    }
    return 0;
}
