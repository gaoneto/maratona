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
    int i, n, a, b, cont=0;
    double c, s;
    scanf("%d", &n);
    for(a=1; ; a++)
    {
        if(a*a>n*n) break;
        for(b=a; ; b++)
        {
            c=a*a+b*b;
            s=sqrt(c);
            if((s-int(s))<EPS) cont++;
            if(s>(double)n) break;
        }
    }
    printf("%d", cont);
    return 0;
}
