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
    if(n>0) printf("%d", n);
    else
    {
        printf("%d", max(n/10, (n/100)*10-(-n)%10));
    }
    return 0;
}
