#include <stdio.h>
#include <iostream>

using namespace std;

int cont[5];

int main()
{
    int n, s, resp=0, aux, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &s);
        cont[s]++;
    }
    resp+=(cont[4]+cont[2]/2);
    cont[2]-=2*(cont[2]/2);
    aux=min(cont[1], cont[3]);
    resp+=aux;
    cont[1]-=aux;
    cont[3]-=aux;
    if(cont[2])
    {
        resp++;
        if(cont[1]) cont[1]-=min(cont[1], 2);
    }
    resp+=(cont[3]+cont[1]/4);
    cont[1]-=4*(cont[1]/4);
    if(cont[1]) resp++;
    printf("%d", resp);
    return 0;
}
