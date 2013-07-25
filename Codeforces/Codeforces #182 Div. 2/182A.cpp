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
    int i, n, m, l, r, a=0, b=0, x;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    {
        scanf("%d", &x);
        if(x==-1) a++;
        else b++;
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &l, &r);
        l--, r--;
        if((r-l+1)%2==1) printf("0\n");
        else
        {
            if(2*a>=(r-l+1) && 2*b>=(r-l+1)) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
