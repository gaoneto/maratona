#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

int c[26];

int main()
{
    int n, i, even=0, odd=0;
    char s[1500];
    cin >> s;
    n=strlen(s);
    for(i=0; i<n; i++) c[s[i]-'a']++;
    for(i=0; i<26; i++)
    {
        if(c[i]%2==0) even++;
        else odd++;
    }
    if(!odd || odd%2==1) printf("First");
    else printf("Second");
    return 0;
}
