#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>
#define INF 1000000000
#define EPS 1e-8
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll pot[110];

int main()
{
    int i, n, size;
    ll resp;
    char s[110];
    cin >> s;
    size=strlen(s);
    pot[0]=1;
    for(i=1; i<110; i++) pot[i]=(pot[i-1]*2LL)%MOD;
    resp=0LL;
    for(i=size-1; i>=0; i--) resp=(resp+(ll)(s[i]-'0')*pot[size-1-i])%MOD;
    resp=(resp*pot[size-1])%MOD;
    cout << resp;
    return 0;
}
