#include <stdio.h>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

int a[64], b[64], resp[64];

int lt(ll x, int p)
{
    ll base=1, v=0;
    int i;
    for(i=63; i>=0; i--)
    {
        v+=base*a[i];
        base*=2;
    }
    v+=(1LL << p);
    if(v<=x) return 1;
    return 0;
}

int gt(ll x, int p)
{
    ll base=1, v=0;
    int i;
    for(i=63; i>=0; i--)
    {
        if(i!=p) v+=base*b[i];
        base*=2;
    }
    if(v>=x) return 1;
    return 0;
}

int main()
{
    ll l, r, aux, val=0, base=1;
    int i, bi=63, c=63;
    cin >> l >> r;
    aux=l;
    while(aux)
    {
        a[bi--]=aux%2;
        aux/=2;
    }
    aux=r;
    while(aux)
    {
        b[c--]=aux%2;
        aux/=2;
    }
    for(i=0; i<64; i++)
    {
        if(a[i]!=b[i]) resp[i]=1;
        else
        {
            if(!a[i] && lt(r, 63-i)) resp[i]=1;
            else if(b[i] && gt(l, i)) resp[i]=1;
            else resp[i]=0;
        }
    }
    for(i=63; i>=0; i--)
    {
        val+=resp[i]*base;
        base*=2;
    }
    cout << val;
    return 0;
}
