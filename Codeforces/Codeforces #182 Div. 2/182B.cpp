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

ll c[100100], t[100100], v, s[100100];

int main()
{
    int i, n, m;
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        cin >> c[i] >> t[i];
        if(i) s[i]=s[i-1]+c[i]*t[i];
        else s[i]=c[i]*t[i];
    }
    for(i=0; i<m; i++)
    {
        cin >> v;
        cout << (lower_bound(s, s+n, v)-s)+1 << endl;
    }
    return 0;
}
