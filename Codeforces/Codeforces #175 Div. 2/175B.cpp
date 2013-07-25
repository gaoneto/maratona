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

int p[100010], vis[100010];

int main()
{
    int i, n, s, t, resp=0, flag=0, cur;
    scanf("%d %d %d", &n, &s, &t);
    for(i=1; i<=n; i++) scanf("%d", &p[i]);
    vis[s]=1;
    cur=s;
    while(s!=t)
    {
        cur=p[cur];
        resp++;
        if(cur==t) break;
        if(vis[cur])
        {
            flag=1;
            break;
        }
        vis[cur]=1;
    }
    if(flag) printf("-1");
    else printf("%d", resp);
    return 0;
}
