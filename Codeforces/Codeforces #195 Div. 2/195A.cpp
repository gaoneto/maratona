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

int mod(int a) { return ((a>0) ? a : -a); }

int main()
{
    int i, x, y, l;
    cin >> x >> y;
    l=mod(x)+mod(y);
    if(x>0 && y>0) printf("%d %d %d %d", 0, l, l, 0);
    if(x>0 && y<0) printf("%d %d %d %d", 0, -l, l, 0);
    if(x<0 && y>0) printf("%d %d %d %d", -l, 0, 0, l);
    if(x<0 && y<0) printf("%d %d %d %d", -l, 0, 0, -l);
    return 0;
}
