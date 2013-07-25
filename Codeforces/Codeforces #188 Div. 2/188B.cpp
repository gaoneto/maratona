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

char s[1000100];
vector<int> heavy, metal;

int main()
{
    int i, n, size;
    ll resp=0LL;
    scanf("%s", s);
    size=strlen(s);
    for(i=4; i<size; i++)
    {
        if(s[i]=='y' && s[i-1]=='v' && s[i-2]=='a' && s[i-3]=='e' && s[i-4]=='h') heavy.push_back(i-4);
        if(s[i]=='l' && s[i-1]=='a' && s[i-2]=='t' && s[i-3]=='e' && s[i-4]=='m') metal.push_back(i-4);
    }
    for(i=0; i<heavy.size(); i++) resp+=((ll)metal.size()-ll(upper_bound(metal.begin(), metal.end(), heavy[i])-metal.begin()));
    cout << resp;
    return 0;
}
