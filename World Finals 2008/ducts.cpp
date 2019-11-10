#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int X, Y, Z, best;
int vis[30][30][30];
int xf, yf, zf;
int oldx, oldy, oldz;
string oldp;
string pf;

bool out(int x, int y, int z) { return (x < 1 || x > X || y < 1 || y > Y || z < 1|| z > Z); }

bool mark(int x0, int y0, int z0, string p0, int v) {
    if(oldp[1] == 'x') {
        int i = oldx;
        int j = oldy;
        int k = oldz;
        while(1) {
            if(x0 > oldx) i++;
            else i--;
            if(vis[i][j][k]+v == 2) return 0;
            if(i==x0) break;
        }
        while(1) {
            if(y0 > oldy) j++;
            if(y0 < oldy) j--;
            if(z0 > oldz) k++;
            if(z0 < oldz) k--;
            if(vis[i][j][k]+v == 2) return 0;
            if(i==x0 && j == y0 && k == z0) break;
        }
        cout<<"EU"<<endl;
        i = oldx;
        j = oldy;
        k = oldz;
        while(1) {
            if(x0 > oldx) i++;
            else i--;
            vis[i][j][k] = vis[i][j][k]+v;
            if(i==x0) break;
        }
        while(1) {
            if(y0 > oldy) j++;
            if(y0 < oldy) j--;
            if(z0 > oldz) k++;
            if(z0 < oldz) k--;
            vis[i][j][k] = vis[i][j][k]+v;
            if(i==x0 && j == y0 && k == z0) break;
        }
    }
    if(oldp[1] == 'y') {
        int i = oldx;
        int j = oldy;
        int k = oldz;
        while(1) {
            if(y0 > oldy) j++;
            else j--;
            if(vis[i][j][k]+v == 2) return 0;
            if(j==y0) break;
        }
        while(1) {
            if(x0 > oldx) i++;
            if(x0 < oldx) i--;
            if(z0 > oldz) k++;
            if(z0 < oldz) k--;
            if(vis[i][j][k]+v == 2) return 0;
            if(i==x0 && j == y0 && k == z0) break;
        }
        i = oldx;
        j = oldy;
        k = oldz;
        while(1) {
            if(y0 > oldy) j++;
            else j--;
            vis[i][j][k] = vis[i][j][k]+v;
            if(j==y0) break;
        }
        while(1) {
            if(x0 > oldx) i++;
            if(x0 < oldx) i--;
            if(z0 > oldz) k++;
            if(z0 < oldz) k--;
            vis[i][j][k] = vis[i][j][k]+v;
            if(i==x0 && j == y0 && k == z0) break;
        } 
    }
    if(oldp[1] == 'z') {
        int i = oldx;
        int j = oldy;
        int k = oldz;
        while(1) {
            if(z0 > oldz) k++;
            else k--;
            if(vis[i][j][k]+v == 2) return 0;
            if(k==z0) break;
        }
        while(1) {
            if(x0 > oldx) i++;
            if(x0 < oldx) i--;
            if(y0 > oldy) j++;
            if(y0 < oldy) j--;
            if(vis[i][j][k]+v == 2) return 0;
            if(i==x0 && j == y0 && k == z0) break;
        }
        i = oldx;
        j = oldy;
        k = oldz;
        while(1) {
            if(z0 > oldz) k++;
            else k--;
            vis[i][j][k] = vis[i][j][k]+v;
            if(k==z0) break;
        }
        while(1) {
            if(x0 > oldx) i++;
            if(x0 < oldx) i--;
            if(y0 > oldy) j++;
            if(y0 < oldy) j--;
            vis[i][j][k] = vis[i][j][k]+v;
            if(i==x0 && j == y0 && k == z0) break;
        }
    }
    return 1;
}

void go(int x0, int y0, int z0, string p0, int n) {
    if(n!=2) {
        if(p0[0] == '+') {
            if(p0[1] == 'z') z0++;
            if(p0[1] == 'y') y0++;
            if(p0[1] == 'x') x0++;
        }
        if(p0[0] == '-') {
            if(p0[1] == 'z') z0--;
            if(p0[1] == 'y') y0--;
            if(p0[1] == 'x') x0--;
        }
    }
    cout<<x0<<" "<<y0<<" "<<z0<<" "<<p0<<endl;
    if(x0==xf && y0==yf && z0==zf && p0==pf) best = min(best, 2-n);
    int _oldx = oldx;
    int _oldy = oldy;
    int _oldz = oldz;
    string _oldp = oldp;
    if(n!=2 && !mark(x0, y0, z0, p0, 1)) return;
    oldx = x0, oldy = y0, oldz = z0;
    oldp = p0;
    if(!out(x0,y0,z0) && n) {
    if(p0 == "+z") {
        go(x0+2,y0,z0+1,"+x",n-1);
        go(x0,y0+2,z0+1,"+y",n-1);
        go(x0-2,y0,z0+1,"-x",n-1);
        go(x0,y0-2,z0+1,"-y",n-1);
        go(x0+1,y0,z0+2,"+x",n-1);
        go(x0,y0+1,z0+2,"+y",n-1);
        go(x0-1,y0,z0+2,"-x",n-1);
        go(x0,y0-1,z0+2,"-y",n-1);
    }
    else if(p0 == "-z") {
        go(x0+2,y0,z0-1,"+x",n-1);
        go(x0,y0+2,z0-1,"+y",n-1);
        go(x0-2,y0,z0-1,"-x",n-1);
        go(x0,y0-2,z0-1,"-y",n-1);
        go(x0+1,y0,z0-2,"+x",n-1);
        go(x0,y0+1,z0-2,"+y",n-1);
        go(x0-1,y0,z0-2,"-x",n-1);
        go(x0,y0-1,z0-2,"-y",n-1);
    }
    else if(p0 == "+y") {
        go(x0+2,y0+1,z0,"+x",n-1);
        go(x0,y0+1,z0+2,"+z",n-1);
        go(x0-2,y0+1,z0,"-x",n-1);
        go(x0,y0+1,z0-2,"-z",n-1);
        go(x0+1,y0+2,z0,"+x",n-1);
        go(x0,y0+2,z0+1,"+z",n-1);
        go(x0-1,y0+2,z0,"-x",n-1);
        go(x0,y0+2,z0-1,"-z",n-1);
    }
    else if(p0 == "-y") {
        go(x0+2,y0-1,z0,"+x",n-1);
        go(x0,y0-1,z0+2,"+z",n-1);
        go(x0-2,y0-1,z0,"-x",n-1);
        go(x0,y0-1,z0-2,"-z",n-1);
        go(x0+1,y0-2,z0,"+x",n-1);
        go(x0,y0-2,z0+1,"+z",n-1);
        go(x0-1,y0-2,z0,"-x",n-1);
        go(x0,y0-2,z0-1,"-z",n-1);
    }
    else if(p0 == "+x") {
        go(x0+1,y0+2,z0,"+y",n-1);
        go(x0+1,y0,z0+2,"+z",n-1);
        go(x0+1,y0-2,z0,"-y",n-1);
        go(x0+1,y0,z0-2,"-z",n-1);
        go(x0+2,y0+1,z0,"+y",n-1);
        go(x0+2,y0,z0+1,"+z",n-1);
        go(x0+2,y0-1,z0,"-y",n-1);
        go(x0+2,y0,z0-1,"-z",n-1);
    }
    else if(p0 == "-x") {
        go(x0-1,y0+2,z0,"+y",n-1);
        go(x0-1,y0,z0+2,"+z",n-1);
        go(x0-1,y0-2,z0,"-y",n-1);
        go(x0-1,y0,z0-2,"-z",n-1);
        go(x0-2,y0+1,z0,"+y",n-1);
        go(x0-2,y0,z0+1,"+z",n-1);
        go(x0-2,y0-1,z0,"-y",n-1);
        go(x0-2,y0,z0-1,"-z",n-1);
    }
    }
    oldx = _oldx, oldy = _oldy, oldz = _oldy;
    oldp = _oldp;
    if(n!=2) mark(x0, y0, z0, p0, -1);
}

int main() {
    int t=1;
    while(cin>>X && X) {
        cin >> Y >> Z;
        int x0, y0, z0;
        string p0;
        cin>>x0>>y0>>z0>>p0>>xf>>yf>>zf>>pf;
        if(pf=="+x") xf++;
        if(pf=="-x") xf--;
        if(pf=="+y") yf++;
        if(pf=="-y") yf--;
        if(pf=="+z") zf++;
        if(pf=="-z") zf--;
        best = 7;
        pf[0] = '-';
        go(x0, y0, z0, p0, 2);
        cout << "Case "<<t++<<": ";
        if(best == 7) cout << "Impossible"<<endl;
        else cout<<best<<endl;
    }
}
