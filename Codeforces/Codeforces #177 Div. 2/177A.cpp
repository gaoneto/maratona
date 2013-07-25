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

int l[100100], r[100100];

int main()
{
    int i, n, k;
    ll sum=0;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        sum+=(r[i]-l[i]+1);
    }
    sum%=k;
    if(!sum) printf("0");
    else cout << ((ll)k-sum);
    return 0;
}
