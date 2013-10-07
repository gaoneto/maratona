#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int v[1111];
ll pot[1111];

int main() {
    ll n;
    int k;
    while(scanf("%lld %d", &n, &k) != EOF) {
        int tam=0;
        for(int i=0;;i++) {
            if(n < k) {
                v[tam++] = n;
                break;
            }
            v[tam++] = n%k;
            n /= k;
        }
        pot[0] = 1;
        for(int i=1;i<=tam;i++) pot[i] = pot[i-1]*k;
        ll ans=0;
        ll x;
        for(int i=1;i<tam;i+=2) {
            if(i==1) {
                ans += k;
                x=k-1;
            }
            else {
                x *= k;
                ans += x;
            }
        }
        if(tam == 1) {
            cout << v[0]+1<<endl;
            continue;
        }
        else if(tam % 2 == 1) {
            int i;
            for(i=tam-1; i>=0; i--) {
                if(i%2==0) {
                    if(v[i]) {
                        if(i==tam-1) ans += (v[i]-1)*pot[i/2];
                        else ans += v[i]*pot[i/2];
                    }
                }
                else {
                    if(v[i]) {
                        ans += pot[(i+1)/2];
                        break;
                    }
                }
            }
            if(i<0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
