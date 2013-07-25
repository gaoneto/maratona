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

char s[100100];
int c[100100];

int main()
{
    int i, n, m, r, l;
    scanf("%s %d", s, &m);
    n=strlen(s);
    c[0]=0;
    for(i=1; i<n; i++)
    {
        c[i]=c[i-1];
        if(s[i]==s[i-1]) c[i]++;
    }
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &l, &r);
        l--, r--;
        printf("%d\n", c[r]-c[l]);
    }
    return 0;
}
