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

int a[110], s[110], pos[110];

int main()
{
    int i, n, q, j, k, p, x, y, resp, flag;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        s[i]=1;
        pos[a[i]]=i;
    }
    for(i=n-1; i>=0; i--) if(pos[i+1]>pos[i]) s[i]+=s[i+1];
    cin >> q;
    for(j=0; j<q; j++)
    {
        cin >> p >> x >> y;
        if(p==1)
        {
            resp=0;
            while(x<=y)
            {
                x+=s[x];
                resp++;
            }
            cout << resp << endl;
        }
        else
        {
            pos[a[x]]=y;
            pos[a[y]]=x;
            swap(a[x], a[y]);
            for(i=1; i<=n; i++) s[i]=1;
            for(i=n-1; i>=0; i--) if(pos[i+1]>pos[i]) s[i]+=s[i+1];
        }
    }
    return 0;
}
