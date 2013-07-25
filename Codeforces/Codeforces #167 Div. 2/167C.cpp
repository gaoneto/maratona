#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <string>
#include <string.h>
#include <cmath>
#include <utility>

using namespace std;

typedef long long ll;

ll a[100010];

int main()
{
    int i, n, m;
    ll w, h;
    cin >> n;
    for(i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    for(i=0; i<m; i++)
    {
        cin >> w >> h;
        cout << max(a[1], a[w]) << endl;
        a[1]=max(a[1], a[w])+h;
    }
    return 0;
}
