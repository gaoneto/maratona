#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <string>
#include <string.h>
#include <cmath>
#include <utility>

using namespace std;

typedef long long ll;

map<ll, ll> m;
map<ll, ll>::iterator it;

ll f(ll a)
{
    if(!a) return 0;
    if(a%2==0) return f(a/2);
    else return f((a-1)/2)+1;
}

int main()
{
    int i, n;
    ll a, v, resp=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        v=f(a);
        if(!m.count(v)) m[v]=1;
        else m[v]++;
    }
    for(it=m.begin(); it!=m.end(); it++) resp+=(((*it).second)*((*it).second-1))/2;
    cout << resp;
    return 0;
}
