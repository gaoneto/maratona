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

vector<int> p1, p2, p3;

int main()
{
    int i, n, a[110], pos=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]>0) pos=1;
    }
    sort(a, a+n);
    if(pos)
    {
        printf("1 %d\n", a[0]);
        printf("1 %d\n", a[n-1]);
        printf("%d", n-2);
        for(i=1; i<n-1; i++) printf(" %d", a[i]);
    }
    else
    {
        printf("1 %d\n", a[0]);
        printf("2 %d %d\n", a[1], a[2]);
        printf("%d", n-3);
        for(i=3; i<n; i++) printf(" %d", a[i]);
    }
    return 0;
}
