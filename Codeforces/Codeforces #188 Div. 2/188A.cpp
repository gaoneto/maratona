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
    ll n, k;
    cin >> n >> k;
    if(k>(n+1)/2)
    {
        k-=(n+1)/2;
        cout << 2*k;
    }
    else
    {
        cout << 2*k-1;
    }
    return 0;
}
