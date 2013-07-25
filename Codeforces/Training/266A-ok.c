#include <stdio.h>

int main()
{
    int resp=0, cont=1, n, i;
    char s[60];
    scanf("%d %s", &n, s);
    for(i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
        {
            cont++;
            if(i==n-1) resp+=(cont-1);
        }
        else
        {
            resp+=(cont-1);
            cont=1;
        }
    }
    printf("%d", resp);
    return 0;
}
