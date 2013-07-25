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

char a[1000010], b[1000010];

int main()
{
    int i, n, sa, sb, j;
    scanf("%s %s", a, b);
    sa=strlen(a);
    sb=strlen(b);
    for(i=0; i<sa && a[i]=='0'; i++);
    for(j=0; j<sb && b[j]=='0'; j++);
    if(!strcmp(a, b)) printf("YES");
    else if(sa!=sb || i==sa || j==sb) printf("NO");
    else printf("YES");
    return 0;
}
