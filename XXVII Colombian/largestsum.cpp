#include <cstdio>
#include <cstring>

using namespace std;

char s[1111111];

int main()
{
    int i, n, sum, a, ans;
    char * pch;
    while(scanf("%[^\n]", s)!=EOF)
    {
        getchar();
        sum=ans=0;
        pch=strtok(s, " ");
        while(pch!=NULL)
        {
            sscanf(pch, "%d", &a);
            sum+=a;
            if(sum>ans) ans=sum;
            if(sum<0) sum=0;
            pch=strtok(NULL, " ");
        }
        printf("%d\n", ans);
    }
    return 0;
}
