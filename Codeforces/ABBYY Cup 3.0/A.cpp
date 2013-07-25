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

char s[100100];
int f[30];
ll resp=1LL;

int main()
{
    int i, n, size, cont=0, j=10;
    scanf("%s", s);
    size=strlen(s);
    if(s[0]=='?' || (s[0]>='A' && s[0]<='J')) resp=9LL;
    if(s[0]>='A' && s[0]<='J')
    {
        f[s[0]-'A']=2;
        j--;
    }
    for(i=1; i<size; i++)
    {
        if(s[i]>='A' && s[i]<='J' && !f[s[i]-'A']) f[s[i]-'A']=1;
        else if(s[i]=='?') cont++;
    }
    for(i=0; i<30; i++) if(f[i]==1)
    {
        resp*=j;
        j--;
    }
    cout << resp;
    for(i=0; i<cont; i++) cout << "0";
    return 0;
}
