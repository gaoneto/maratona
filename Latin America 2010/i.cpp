#include <stdio.h>

int p[100001];

int mod(int a)
{
    return ((a>0) ? a : -a);
}

int gcd(int a, int b)
{
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    int t, q, s, d, i, mdc;
    while(scanf("%d %d", &t, &q) && (t || q))
    {
        for(i=0; i<t; i++)
            scanf("%d", &p[i]);
        mdc=mod(2*p[0]);
        for(i=1; i<t; i++)
            mdc=gcd(mdc, mod(2*p[i]));
        for(i=0; i<q; i++)
        {
            scanf("%d %d", &s, &d);
            if(t>1)
            {
                if(mod(d-s)%mdc==0 || mod(d+s)%mdc==0) printf("Y");
                else printf("N");
            }
            else if(d+s==2*p[0]) printf("Y");
            else printf("N");
            if(i!=q-1) printf(" ");
        }
        printf("\n");
    }
    return 0;    
}
