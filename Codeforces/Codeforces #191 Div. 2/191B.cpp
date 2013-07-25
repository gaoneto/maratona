#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>
#define INF 1000000000
#define EPS 1e-8
#define MAX 2000000


using namespace std;

typedef long long ll;

unsigned int a[(MAX>>6)+10];
int prime[670000], nprimes=1;

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


int main()
{
    int i, n;
    sieve(MAX);
    scanf("%d", &n);
    for(i=0; i<n; i++) printf("%d ", prime[i]);
    return 0;
}
