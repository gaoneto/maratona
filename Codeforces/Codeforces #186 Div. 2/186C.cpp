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

int a[2000100];
int pot[15];

int main()
{
    int i, n, j, cont=0, k=0;
    ll resp=0LL;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    pot[0]=1;
    for(i=1; i<15; i++) pot[i]=pot[i-1]*4;
    for(j=0; j<15; j++) if(pot[j]==n) break;
    j++;
    sort(a, a+n);
    for(i=n-1; i>=0; i--)
    {
        resp+=(ll)a[i]*(ll)j;
        cont++;
        if(cont==pot[k])
        {
            j--;
            k++;
        }
    }
    cout << resp;
    return 0;
}
