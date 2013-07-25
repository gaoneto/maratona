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
    int i, n, cl=0, cr=0, il=-1, ir=-1, fr=-1, fl=-1;
    char s[1100];
    scanf("%d %s", &n, s);
    for(i=0; i<n; i++)
    {
        if(s[i]=='R')
        {
            cr=1;
            if(ir==-1) ir=i+1;
            fr=i+1;
        }
        if(s[i]=='L')
        {
            cl=1;
            if(il==-1) il=i+1;
            fl=i+1;
        }
    }
    if(cr && cl) printf("%d %d", ir, fr);
    else if(cr) printf("%d %d", ir, fr+1);
    else printf("%d %d", fl, il-1);
    return 0;
}
