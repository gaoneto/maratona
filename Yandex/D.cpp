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

using namespace std;

typedef long long ll;

int main()
{
    int i, n, f=0, a=0, b=0, c=0, d=0;
    ll x, y, z;
    cin >> x >> y >> z;
    if(x+y==z) f++, a=1;
    if(x-y==z) f++, b=1;
    if(x*y==z) f++, c=1;
    if(y!=0 && x==z*y) f++, d=1;
    if(f==1)
    {
        if(a) cout << "+";
        if(b) cout << "-";
        if(c) cout << "*";
        if(d) cout << "/";
    }
    else cout << "Invalid";
    return 0;
}
