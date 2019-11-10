#include <cstdio>
#include <iostream>
#include <stdlib.h>
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
    int i, n, t, r, m, k, a[10], aux=1, j, x, y, z, f, n1, n2, n3;
    srand (time(NULL));
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &r, &n, &m, &k);
        printf("Case #%d:\n", aux++);
        for(i=0; i<r; i++)
        {
            f=0;
            for(j=0; j<k; j++) scanf("%d", &a[j]);
            for(x=2; x<=m; x++) for(y=2; y<=m; y++) for(z=2; z<=m; z++) for(j=0; j<k; j++) if(x*y*z==a[j])
            {
                f=1;
                n1=x, n2=y, n3=z;
            }
            if(f) printf("%d%d%d\n", n1, n2, n3);
            else
            {
                n1=n2=n3=0;
                while(n1<2) n1=rand()%m;
                while(n2<2) n2=rand()%m;
                while(n3<2) n3=rand()%m;
                printf("%d%d%d\n", n1, n2, n3);
            }
        }
    }
    return 0;
}
