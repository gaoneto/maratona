#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> diagonal[1100];
int h[501][501];

int main()
{
    int i, j, n, m, q, l, u, maximo, low, up, pos;
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        for(i=0; i<n+m-1; i++) diagonal[i].clear();
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                scanf("%d", &h[i][j]);
                diagonal[n+j-i-1].push_back(h[i][j]);
            }
        scanf("%d", &q);
        for(i=0; i<q; i++)
        {
            maximo=0;
            scanf("%d %d", &l, &u);
            for(j=0; j<n; j++)
            {
                low=lower_bound(h[j], h[j]+m, l)-h[j];
                if(low<m)
                {
                    up=upper_bound(diagonal[n+low-j-1].begin(), diagonal[n+low-j-1].end(), u)-diagonal[n+low-j-1].begin();
                    if(low<j) pos=low;
                    else pos=j;
                    maximo=max(maximo, up-pos);
                }
            }
            printf("%d\n", maximo);
        }
        printf("-\n");
    }
    return 0;
}
