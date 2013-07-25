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

char s[1000100];

int main()
{
    int i, n, k, t=0, j;
    scanf("%d %d", &n, &k);
    if(k>n || (n>1 && k==1)) printf("-1");
    else if(k==1) printf("a");
    else
    {
        for(i=0; i<n-k+2; i++)
        {
            if(i%2) s[t++]='b';
            else s[t++]='a';
        }
        j=2;
        for(; i<n; i++)
        {
            s[t++]='a'+j;
            j++;
        }
        s[t]='\0';
        printf("%s", s);
    }
    return 0;
}
