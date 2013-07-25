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
    int i, n, sum=0, a, resp=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        sum+=a;
    }
    for(i=1; i<=5; i++) if((i+sum)%(n+1)!=1) resp++;
    printf("%d", resp);
    return 0;
}
