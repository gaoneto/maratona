#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int dez[9]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int nove[9]={0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999};

int qnove(int x)
{
    int i;
    for(i=1; i<9; i++)
        if(x%dez[i]!=nove[i])
        {
            if(x>nove[i-1]) return i-1;
            else return i-2;
        }
    return 7;
}

vector<int> countDig(int a)
{
    vector<int> dig(10, 0);
    int n, i;
    while(a)
    {
        n=qnove(a);
        for(i=a/dez[n]; i>0; i/=10)
        dig[i%10]+=dez[n];
        if(n)
            for(i=0; i<10; i++)
                dig[i]+=dez[n-1]*n;
        a-=dez[n];
    }
    return dig;
}

int main()
{
    int a, b, i;
    while(scanf("%d %d", &a, &b) && (a || b))
    {
        vector<int> digA=countDig(a-1);
        vector<int> digB=countDig(b);
        for(i=0; i<10; i++)
            printf("%d ", digB[i]-digA[i]);
        printf("\n");
    }
    return 0;
}
