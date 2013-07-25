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
    int i, n, l, x[20], foo=0, bar=0, baz=0, quz=1;
    scanf("%d", &l);
    for(i=0; i<l; i++)
    {
        scanf("%d", &x[i]);
        foo+=x[i];
        bar++;
        if(foo*quz>bar*baz)
        {
            baz=foo;
            quz=bar;
        }
    }
    printf("%lf", (double)baz/quz);
    return 0;
}
