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

double d[111111], sum[111111];

int main()
{
    int i, n, m;
    double r, resp=0;
    cin >> m >> r;
    d[0]=sum[0]=2*r;
    d[1]=2*r+r*sqrt(2);
    d[2]=2*r+2*r*sqrt(2);
    sum[1]=d[0]+d[1];
    sum[2]=sum[1]+d[2];
    for(i=3; i<m; i++)
    {
        d[i]=d[i-1]+2*r;
        sum[i]=sum[i-1]+d[i];
    }
    for(i=0; i<m; i++)
    {
        resp+=sum[m-i-1];
        if(i) resp+=(sum[i]-d[0]);
    }
    printf("%.10lf", resp/(double)m/(double)m);
    return 0;
}
