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
    int i, n, a, g, sa=0, sg=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> g;
        if(sa-sg+a<=500)
        {
            sa+=a;
            cout << "A";
        }
        else
        {
            sg+=g;
            cout << "G";
        }
    }
    return 0;
}
