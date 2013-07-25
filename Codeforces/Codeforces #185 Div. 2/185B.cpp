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
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("%.12lf", (a*d)/(b*c+a*d-a*c));
    return 0;
}
