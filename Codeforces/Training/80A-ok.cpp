#include <stdio.h>
#include <iostream>

int prime[100], nprimes;

void find_primes(int n) 
{
    int j, k;
    nprimes=1;
    prime[0]=2; 
    bool is_prime;
    for(k=3; k<=n; k+=2) 
    {
        is_prime=true;
        for(j=0; j<nprimes && prime[j]*prime[j]<=k; ++j)
        if(k%prime[j]==0) 
        {
            is_prime=false; 
            break;
        }
        if(is_prime) prime[nprimes++]=k;
    }
}

int main()
{
    int n, m, i;
    find_primes(100);
    scanf("%d %d", &n, &m);
    for(i=0; prime[i]<=n; i++);
    printf("%s", prime[i]==m ? "YES" : "NO");
    return 0;    
}
