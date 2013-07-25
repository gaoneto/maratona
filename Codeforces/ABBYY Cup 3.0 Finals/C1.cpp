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

int main()
{
    int i, n, j, resp=0;
    cin >> n;
    while(n)
    {
        i=n;
        j=0;
        while(i)
        {
            if((i%10)>j) j=i%10;
            i/=10;
        }
        n-=j;
        resp++;
    }
    cout << resp;
    return 0;
}
