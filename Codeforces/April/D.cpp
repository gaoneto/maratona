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
    int i, n, size;
    char s[100];
    scanf("%s %d", s, &n);
    size=strlen(s);
    for(i=0; i<size; i++) s[i]=tolower(s[i]);
    for(i=0; i<size; i++)
    {
        if(s[i]<n+97) s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
    }
    printf("%s", s);
    return 0;
}

