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

int h[1001];

int main()
{
    int i, n, a, maximo=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        h[a]++;
    }
    for(i=0; i<1001; i++) if(h[i]>maximo) maximo=h[i];
    if(n%2)
    {
        if(maximo>(n/2)+1) printf("NO");
        else printf("YES");
    }
    else
    {
        if(maximo>(n/2)) printf("NO");
        else printf("YES");
    }
    return 0;
}
