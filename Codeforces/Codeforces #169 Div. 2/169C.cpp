#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

ll a[200010], s[200010], freq[200010], resp=0;

int main()
{
    int n, i, q, l, r, sum=0;
    cin >> n >> q;
    for(i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for(i=0; i<q; i++)
    {
        cin >> l >> r;
        s[l-1]++;
        s[r]--;
    }
    for(i=0; i<n; i++)
    {
        freq[i]=sum+s[i];
        sum+=s[i];
    }
    sort(freq, freq+n);
    for(i=0; i<n; i++) resp+=freq[i]*a[i];
    cout << resp;
    return 0;
}
