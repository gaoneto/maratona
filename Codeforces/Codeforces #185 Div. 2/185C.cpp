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
    int i, n, k, j;
    scanf("%d %d", &n, &k);
    if(2*k>=n*(n-1)) printf("no solution");
    else
    {
        for(i=0; i<n; i++) printf("0 %d\n", i);
    }
    return 0;
}
