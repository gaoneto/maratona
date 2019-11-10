#include <stdio.h>
#include <iostream>
#include <algorithm>

int d[101];

bool compara(int a, int b)
{
     return (d[a]<d[b]);
}

using namespace std;

int main()
{
    int n, c, k, i, x, ordem[101], min;
    do
    {
        scanf("%d %d %d", &n, &c, &k);
        if(n!=0 || c!=0 || k!=0)
        {
            for(i=1; i<=k; i++)
            {
                ordem[i]=i;
                d[i]=0;
            }
            for(i=1; i<=n*c; i++)
            {
                scanf("%d", &x);
                d[x]++;
            }
            stable_sort(ordem+1, ordem+k+1, compara);
            i=1;
            min=d[ordem[i]];
            while(d[ordem[i]]==min && i<=k)
            {
                printf("%d ", ordem[i]);
                i++;
            }
            printf("\n");
        }
    }while(n!=0 || c!=0 || k!=0);
    return 0;
}
