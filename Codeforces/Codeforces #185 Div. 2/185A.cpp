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
    int i, n, f=0, r=0, size;
    char s[1000];
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        getchar();
        scanf("%[^\n]", s);
        size=strlen(s);
        f=r=0;
        if(size>=5)
        {
            if(s[0]=='m' && s[1]=='i' && s[2]=='a' && s[3]=='o' && s[4]=='.') r=1;
            if(s[size-1]=='.' && s[size-2]=='a' && s[size-3]=='l' && s[size-4]=='a' && s[size-5]=='l') f=1;
        }
        if(f && r) printf("OMG>.< I don't know!");
        else if(f) printf("Freda's");
        else if(r) printf("Rainbow's");
        else printf("OMG>.< I don't know!");
        printf("\n");
    }
    return 0;
}
