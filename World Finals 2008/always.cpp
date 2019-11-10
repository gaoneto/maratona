#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll d, c[111], INF=100000000;
int grau;

string s;

void parse() {
    int pos = s.find("/");
    stringstream ss; ss<<s.substr(pos+1); ss>>d;
    s = s.substr(1, pos-2);
    for(int i=0;i<111;i++) c[i]=0;
    pos=0;
    grau=0;
    while(pos < s.size()) {
        int nn = s.find("n", pos);
        if(nn == string::npos) {
            stringstream ss; ss<<s.substr(pos); ss>>c[0];
            break;
        }
        else {
            int x;
            if(nn==pos) x=1;
            else if(nn==pos+1 && s[pos] == '-') x=-1;
            else if(nn==pos+1 && s[pos] == '+') x=1;
            else { stringstream ss; ss<<s.substr(pos, nn-pos); ss>>x; }
            int e;
            if(nn+1 != s.size() && s[nn+1] == '^') {
                int j=nn+2;
                while(j!=s.size() && s[j]!='+'&&s[j]!='-') j++;
                stringstream ss; ss<<s.substr(nn+2, j-nn-2); ss>>e;
                pos = j;
            }
            else {
                e=1;
                pos = nn+1;
            }
            c[e] = x;
            grau = max(grau, e);
        }
    }
}

int main() {
    int t=1, i, j, ok;
    while(cin>>s && s!=".") {
        parse();
        printf("Case %d: ", t++);
        ok=1;
        for(i=1; i<=grau+1 && ok; i++)
        {
            ll r=0, e=1;
            for(j=0; j<=grau; j++)
            {
                r=(r+(e*c[j])%d+INF*d)%d;
                e=(e*(ll)i)%d;
            }
            if(r) ok=0;
        }
        printf("%s\n", ok ? "Always an integer" : "Not always an integer");
    }
    return 0;
}
