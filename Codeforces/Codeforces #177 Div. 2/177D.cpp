#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll i, n, c2=1, k, c1=1;
    cin >> n >> k;
    for(i=1; i<k; i++) c1=(c1*k)%MOD;
    for(i=0; i<n-k; i++) c2=(c2*(n-k))%MOD;
    cout << (c1*c2)%MOD;
    return 0;
}
