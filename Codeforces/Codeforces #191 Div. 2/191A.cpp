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
    int i, n, j, k, cont, resp=0, a[110];
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            a[j]=1-a[j];
            cont=0;
            for(k=0; k<n; k++) if(a[k]) cont++;
            if(cont>resp) resp=cont;
        }
        for(j=i; j<n; j++) a[j]=1-a[j];
    }
    printf("%d", resp);
    return 0;
}
