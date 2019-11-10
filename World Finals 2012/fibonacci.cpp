#include <bits/stdc++.h>
using namespace std;

string f0, f1;
int n, step;

int calc(string p, string s) {
    if(s.size() < p.size()) return 0;
    int ret=0, i=0;
    while(1) {
        int pos = s.find(p, i);
        if(pos == string::npos) break;
        ret++;
        i = pos+1;
    }
    return ret;
}

int main() {
    string p;
    int T=1;
    while(scanf("%d", &n) != EOF) {
        printf("Case %d: ", T++);
        cin>>p;
        int t=p.size();
        f0="0", f1="1";
        step=1;
        while(f0.size() < 2*t-2 && step < n) {
            string aux = f0;
            f0 = f1;
            f1 += aux;
            step++;
        }
        if(n==0) {
            if(p=="0") cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(step == n) {
            cout << calc(p, f1) << endl;
        }
        else {
            string ini0, fim0, ini1, fim1;
            long long num0, num1;
            ini0 = f0.substr(0, t-1);
            fim0 = f0.substr(f0.size()-(t-1), t-1);
            ini1 = f1.substr(0, t-1);
            fim1 = f1.substr(f1.size()-(t-1), t-1);
            num0 = calc(p, f0);
            num1 = calc(p, f1);
            while(step < n) {
                long long auxnum0 = num0;
                string auxini0 = ini0;
                string auxfim0 = fim0;
                
                num0 = num1;
                ini0 = ini1;
                fim0 = fim1;

                num1 += auxnum0 + calc(p, fim1+auxini0);
                fim1 = auxfim0;
                step++;
            }
            cout << num1 << endl;
        }
    }
    return 0;
}
