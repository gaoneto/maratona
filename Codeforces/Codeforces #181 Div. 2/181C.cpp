#include <cstdio>
#include <map>
#include <iostream>
#define MAX 10000
#define MOD 1000000007

using namespace std;

typedef long long ll;

unsigned int a[(MAX>>6)+10];
int nprimes=1, k;
int prime[10000], p[2000], e[2000];
map<int, int> m;

void sieve(int d)
{
    int p_1, q_1, p_2, q_2, i, j;
    for(i=3; i*i<d; i+=2)
    {
        p_1=(i-3)>>6;
        q_1=((i-3)>>1)&31;
        if(!(a[p_1] & (1L<<q_1))) 
            for(j=i*i; j<d; j+=i) 
                if(j&1) 
                {
                    p_2=(j-3)>>6,q_2=((j-3)>>1)&31;
                    a[p_2]|=(1L<<q_2);
                }
    }
    prime[0]=2;
    for(i=3; i<d; i+=2) 
    {
        p_1=(i-3)>>6;
        q_1=((i-3)>>1)&31;
        if(!(a[p_1] & (1L<<q_1))) prime[nprimes++]=i;
    }
}

void factor(int n)
{
    int j;
    k=0;
    for(j=0; prime[j]*prime[j]<=n; ++j)
        if(n%prime[j]==0)
        {
            p[k]=prime[j];
            e[k]=0;
            while(n%prime[j]==0)
            {
                n/=prime[j];
                e[k]++;
            }
            if(!m.count(p[k])) m[p[k]]=e[k];
            else m[p[k]]+=e[k];
            ++k;
        }
    if(n!=1)
    {
        p[k]=n;
        e[k]=1;
        if(!m.count(p[k])) m[p[k]]=e[k];
        else m[p[k]]+=e[k];
        ++k;
    }
}

int main()
{
    int i, n, x;
    ll resp, divide, primo, lo, mid, hi;
    sieve(MAX);
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &x);
        factor(x);
    }
    k=0;
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        p[k]=(*it).first;
        e[k++]=(*it).second;
    }
    lo=1;
    hi=9000000000000000000LL;
    mid=(lo+hi)/2;
    int f;
    while(lo<hi)
    {
        f=0;
        for(i=0; i<k; i++)
        {
            primo=p[i];
            divide=0;
            while(mid>=primo)
            {
                divide+=(mid/primo);
                primo*=prime[i];
            }
            if(divide<e[i])
            {
                f=1;
                break;
            }
        }
        if(f) lo=mid+1;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    cout << mid;
    return 0;
}
