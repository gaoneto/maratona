#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int prime[200000], nprimes, row[501], col[501];

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
    int i, j, n, m, mat[501][501], minimo=1000000000, ind;
    find_primes(101000);
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &mat[i][j]);
    for(i=0; i<n; i++) for(j=0; j<m; j++)
    {
        ind=lower_bound(prime, prime+nprimes, mat[i][j])-prime;
        row[i]+=prime[ind]-mat[i][j];
    }
    for(j=0; j<m; j++) for(i=0; i<n; i++)
    {
        ind=lower_bound(prime, prime+nprimes, mat[i][j])-prime;
        col[j]+=prime[ind]-mat[i][j];
    }
    for(i=0; i<n; i++) if(row[i]<minimo) minimo=row[i];
    for(i=0; i<m; i++) if(col[i]<minimo) minimo=col[i];
    printf("%d", minimo);
    return 0;
}
