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

ll a[100010], x;
set<ll> s;
set<ll>::iterator it;

int main()
{
    int i, n, cont, bit=0, f, tot;
    cin >> n;
    for(i=0; i<n; i++) cin >> a[i];
    for(i=0; i<n; i++)
    {
        x=a[i];
        while(s.count(x))
        {
            s.erase(x);
            x++;
        }
        s.insert(x);
    }
    it=s.end();
    it--;
    cout << *(it)-(int)s.size()+1;
    return 0;
}
