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
    int i=0, x, y, d=0, p=1, j=0, resp=0, cont=0, l=0, flag=0;
    scanf("%d %d", &x, &y);
    while(i!=x || j!=y)
    {
        if(d==0) i++;
        else if(d==1) j++;
        else if(d==2) i--;
        else j--;
        cont++;
        if(flag)
        {
            resp++;
            flag=0;
        }
        if(cont==p)
        {
            d=(d+1)%4;
            l++;
            if(l%2==0) p++;
            cont=0;
            flag=1;
        }
    }
    printf("%d", resp);
    return 0;
}
