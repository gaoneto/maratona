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
    int i, n;
    scanf("%d", &n);
    if(n%2==0) printf("-1");
    else
    {
        for(i=0; i<n; i++) printf("%d ", i);
        printf("\n");
        for(i=0; i<n; i++) printf("%d ", (i+2)%n);
        printf("\n");
        for(i=0; i<n; i++) printf("%d ", (i+(i+2)%n)%n);
    }
    return 0;
}
