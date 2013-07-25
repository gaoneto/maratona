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
    int i, n, size, ok;
    char s[1000];
    scanf("%s", s);
    size=strlen(s);
    for(i=0; i<size; i++)
    {
        ok=0;
        if(s[i]=='1') ok=1;
        if(i && s[i]=='4' && s[i-1]=='1') ok=1;
        if(i>1 && s[i]=='4' && s[i-1]=='4' && s[i-2]=='1') ok=1;
        if(!ok) break;
    }
    if(!ok) printf("NO");
    else printf("YES");
    return 0;
}
