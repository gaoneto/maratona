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

int main()
{
    int i, n, k, j;
    scanf("%d %d", &n, &k);
    for(i=1; i<n-k; i++) printf("%d ", i);
    for(i=k+1, j=n; i>0; i--, j--) printf("%d ", j);
    return 0;
}
