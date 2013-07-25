#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <string>
#include <string.h>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int i, n, dig[10], j;
    scanf("%d", &n);
    for(i=n+1; ; i++)
    {
        j=i;
        memset(dig, 0, sizeof(dig));
        while(j)
        {
            dig[j%10]++;
            j/=10;
        }
        for(j=0; j<10; j++) if(dig[j]>1) break;
        if(j==10)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
