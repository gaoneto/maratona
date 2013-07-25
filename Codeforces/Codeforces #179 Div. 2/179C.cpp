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

using namespace std;

typedef long long ll;

ll a[100010], inc[100010], l[100010], r[100010], d[100010], tot[100010];

int main()
{
    int i, n, k, m, x, y;
    cin >> n >> m >> k;
    for(i=0; i<n; i++) cin >> a[i];
    for(i=0; i<m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;
    }
    for(i=0; i<k; i++)
    {
        cin >> x >> y;
        x--;
        inc[x]++;
        inc[y]--;
    }
    for(i=1; i<m; i++) inc[i]+=inc[i-1];
    for(i=0; i<m; i++)
    {
        tot[l[i]]+=inc[i]*d[i];
        tot[r[i]]-=inc[i]*d[i];
    }
    for(i=1; i<n; i++) tot[i]+=tot[i-1];
    for(i=0; i<n; i++) cout << a[i]+tot[i] << " ";
    return 0;
}
