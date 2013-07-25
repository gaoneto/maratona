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
    int i, n, x=0, size;
    char op[10];
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> op;
        size=strlen(op);
        if(op[0]=='+' || op[size-1]=='+') x++;
        else x--;
    }
    cout << x;
    return 0;
}
