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

int g[3], flag=0;
char s[10];

void go(int p, int q, int r, int a, int b, int c)
{
    if(flag) return;
    if(a==g[0] && b==g[1] && c==g[2] && !p && !q && !r)
    {
        flag=1;
        return;
    }
    if(p) go(p-1, q, r, b, a, c);
    if(q) go(p, q-1, r, c, b, a);
    if(r) go(p, q, r-1, a, c, b);
}

int main()
{
    int i, n, p, q, r;
    cin >> p >> q >> r >> s;
    for(i=0; i<3; i++)
    {
        if(s[i]=='R') g[i]=0;
        if(s[i]=='G') g[i]=1;
        if(s[i]=='B') g[i]=2;
    }
    if(p%2==0) p=min(p, 2);
    else p=min(p, 3);
    if(q%2==0) q=min(q, 2);
    else q=min(q, 3);
    if(r%2==0) r=min(r, 2);
    else r=min(r, 3);
    go(p, q, r, 0, 1, 2);
    printf("%s", (flag) ? "Yes" : "No");
    return 0;
}
