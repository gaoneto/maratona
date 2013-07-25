#include <stdio.h>
#include <string.h>

int main()
{
    int i, size, cont=1, flag=0;
    char s[110];
    scanf("%s", s);
    size=strlen(s);
    for(i=1; i<size; i++)
    {
        if(s[i]==s[i-1])
        {
            cont++;
            if(cont>6)
            {
                flag=1;
                break;
            }
        }
        else cont=1;
    }
    printf("%s", (flag) ? "YES" : "NO");
    return 0;
}
