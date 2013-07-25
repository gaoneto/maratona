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
#define INF 10000000000000000LL
#define EPS 1e-8

using namespace std;

typedef long long ll;

ll a[300100], sum[300100], maximo=-INF, sl, sr, delta;
map<ll, pair<int, int> > m;
map<ll, pair<int, int> >::iterator it;
vector<int> v;

int main()
{
    int i, n, l, r;
    cin >> n;
    sum[0]=0;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1];
        if(a[i]>0) sum[i]+=a[i];
        if(m.count(a[i])) m[a[i]].second=i;
        else m[a[i]]=make_pair(i, 0);
    }
    for(it=m.begin(); it!=m.end(); it++)
    {
        if((*it).second.second==0) continue;
        sr=sum[(*it).second.second];
        sl=sum[(*it).second.first-1];
        delta=0LL;
        if((*it).first<0) delta=2*((*it).first);
        if((sr-sl+delta)>maximo)
        {
            maximo=sr-sl+delta;
            l=(*it).second.first;
            r=(*it).second.second;
        }
    }
    for(i=1; i<l; i++) v.push_back(i);
    for(i=l+1; i<r; i++) if(a[i]<0) v.push_back(i);
    for(i=r+1; i<=n; i++) v.push_back(i);
    cout << maximo << " " << (int)v.size() << endl;
    for(i=0; i<v.size(); i++) cout << v[i] << " ";
    return 0;
}
