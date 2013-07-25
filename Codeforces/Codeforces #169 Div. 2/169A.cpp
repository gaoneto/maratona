#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

int main()
{
    int i, n;
    ll f, t, maxi=-10000000000LL, k, v;
    cin >> n >> k;
    for(i=0; i<n; i++)
    {
        cin >> f >> t;
        if(t>k) v=f-t+k;
        else v=f;
        if(v>maxi) maxi=v;
    }
    cout << maxi;
    return 0;
}
