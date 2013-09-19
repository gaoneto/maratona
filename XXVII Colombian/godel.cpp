#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int i, n, c, ans;
    char s[11111];
    while(scanf("%s", s)!=EOF)
    {
        ans=c=0;
        n=strlen(s);
        for(i=0; i<n; i++)
        {
            if(s[i]=='1')
            {
                if(!c) c+=2;
                else c++;
            }
            else
            {
                c=max(0, c-1);
                if(!c) ans++;
            }
        }
        printf("%d\n", !c ? ans : 0);
    }
    return 0;
}
