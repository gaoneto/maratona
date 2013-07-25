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
#include <algorithm>

using namespace std;

typedef long long ll;

int mod(int a) { return ((a>0) ? a : -a); }

int a[300010], vis[300010], ja[300010];

int main()
{
    int i, n, cur=1;
    ll resp=0LL;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]>=1 && a[i]<=n && !vis[a[i]]) vis[a[i]]=1;
    }
    sort(a, a+n);
    if(a[0]>=1 && a[0]<=n) ja[0]=1;
    for(i=1; i<n; i++) if(a[i]!=a[i-1]) ja[i]=1;
    for(i=0; i<n; i++) if(a[i]<1)
    {
        while(cur<=n && vis[cur]) cur++;
        resp+=(ll)(mod(a[i]-cur));
        vis[cur++]=1;
    }
    cur=n;
    for(i=n-1; i>=0; i--) if(a[i]>n)
    {
        while(cur>0 && vis[cur]) cur--;
        resp+=(ll)(mod(a[i]-cur));
        vis[cur--]=1;
    }
    cur=1;
    for(i=0; i<n; i++) if(a[i]>=1 && a[i]<=n && !ja[i])
    {
        while(cur<=n && vis[cur]) cur++;
        if(cur!=n+1)
        {
            resp+=(ll)(mod(a[i]-cur));
            vis[cur++]=1;
        }
    }
    cout << resp;
    return 0;
}
