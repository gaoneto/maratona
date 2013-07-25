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

int a[110][110];

int mod(int a) { return ((a>0) ? a : -a); }

int main()
{
    int i, n, m, d, j, flag=0, modulo, maximo=0, minimo=100000, resp=1000000000, k, sum;
    scanf("%d %d %d", &n, &m, &d);
    for(i=0; i<n; i++) for(j=0; j<m; j++)
    {
        scanf("%d", &a[i][j]);
        if(!i && !j) modulo=a[i][j]%d;
        else if(a[i][j]%d!=modulo) flag=1;
        if(a[i][j]>maximo) maximo=a[i][j];
        if(a[i][j]<minimo) minimo=a[i][j];
    }
    if(flag) printf("-1");
    else
    {
        for(i=minimo; i<=maximo; i+=d)
        {
            sum=0;
            for(j=0; j<n; j++) for(k=0; k<m; k++) sum+=((mod(a[j][k]-i))/d);
            if(sum<resp) resp=sum;
        }
        if(resp==1000000000) printf("-1");
        else printf("%d", resp);
    }
    return 0;
}
