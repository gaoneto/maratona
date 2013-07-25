#include <stdio.h>

char q[60];

int main()
{
    int i, j, n, t;
    scanf("%d %d %s", &n, &t, q);
    for(i=0; i<t; i++) for(j=1; j<n; j++) if(q[j]=='G' && q[j-1]=='B')
    {
        q[j]='B';
        q[j-1]='G';
        j++;
    }
    printf("%s", q);
    return 0;
}
