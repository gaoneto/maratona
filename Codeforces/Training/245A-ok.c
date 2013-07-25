#include <stdio.h>

int x[3], y[3];

int main()
{
    int i, t, a, b, n;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d", &t, &a, &b);
        x[t]+=a, y[t]+=b;
    }
    printf("%s\n", x[1]>=y[1] ? "LIVE" : "DEAD");
    printf("%s", x[2]>=y[2] ? "LIVE" : "DEAD");
}

