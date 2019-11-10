//Solução utilizando BIT
#include <stdio.h>

long long cur[100010], tree[100010], pot[100010], poti[100010], p;
int l;

long long fast_exp(long long a, long long n)
{
    long long i=1;
    while(n)
    {
        if(n & 1) i=(i*a)%p;
        n/=2;
        a=(a*a)%p;
    }
    return i;
}

long long read(int idx)
{
    long long sum=0;
    while(idx)
    {
        sum=(sum+tree[idx])%p;
        idx-=(idx & -idx);
    }
    return sum;
}

void update(int idx, long long val)
{
    while(idx<=l+5)
    {
        tree[idx]=(tree[idx]+val)%p;
        idx+=(idx & -idx);
    }
}

int main()
{
    int i, n, x, y;
    long long b, inv, r;
    char c[2];
    while(scanf("%lld %lld %d %d", &b, &p, &l, &n) && (b || p || l || n))
    {
        inv=fast_exp(b, p-2);
        pot[0]=poti[0]=1;
        tree[0]=cur[0]=0;
        for(i=1; i<l+5; i++)
        {
            pot[i]=(pot[i-1]*b)%p;
            poti[i]=(poti[i-1]*inv)%p;
            tree[i]=cur[i]=0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%s %d %d", c, &x, &y);
            if(c[0]=='E')
            {
                update(x, -((cur[x]*pot[l-x])%p));
                cur[x]=(long long)y;
                update(x, (cur[x]*pot[l-x])%p);
            }
            else
            {
                r=(read(y)-read(x-1))%p;
                while(r<=0) r+=p;
                r=(r*poti[l-y])%p;
                printf("%lld\n", r);
            }
        }
        printf("-\n");
    }
    return 0;
}
