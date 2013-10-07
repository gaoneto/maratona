#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int h, w, c, v[11];
    while(scanf("%d %d %d", &h, &w, &c)!=EOF)
    {
        for(int i=0;i<c;i++) cin>>v[i];
        int m[11][11];
        int color = 0, ind=0;
        for(int j=0;j<w;j++) for(int i=h-1;i>=0;i--) {
            while(color != c) {
                if(ind == v[color]) {
                    ind = 0;
                    color++;
                }
                else break;
            }
            m[i][j] = color+1;
            ind++;
        }
        for(int i=0;i<h;i++) {
            cout << m[i][0];
            for(int j=1;j<w;j++) cout<< m[i][j];
            cout << endl;
        }
    }
    return 0;
}
