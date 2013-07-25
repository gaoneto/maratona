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

int a[110], b[110], open[110];

int main()
{
    int i, n, j, resp=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &a[i], &b[i]);
    for(i=0; i<n; i++) for(j=0; j<n; j++) if(j!=i && a[i]==b[j]) open[i]=1;
    for(i=0; i<n; i++) if(!open[i]) resp++;
    printf("%d", resp);
    return 0;
}
