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
    int i, n, size, resp=0;
    char s[2010];
    cin >> n >> s;
    size=strlen(s);
    for(i=n; i<size; i+=n) if(s[i-1]==s[i-2] && s[i-2]==s[i-3]) resp++;
    cout << resp;
    return 0;
}
