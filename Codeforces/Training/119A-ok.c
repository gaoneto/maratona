#include <stdio.h>

int gcd(int a, int b) { return (b) ? gcd(b, a%b) : a; }

int main()
{
    int a, b, n, cont=0;
    scanf("%d %d %d", &a, &b, &n);
    while(n)
    {
        n-=gcd((cont%2==0) ? a : b, n);
        cont++;
    }
    printf("%s", (cont%2==0) ? "1" : "0");
    return 0;
}
