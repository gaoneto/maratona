#include <stdio.h>
#include <string.h>
#include <ctype.h>

int fast_exp(int a, int n)
{
    int i;
    i=1;
    while(n>0)
    {
        if(n%2==1) i=i*a;
        n/=2;
        a=a*a;
    }
    return i;
}

int main()
{
    int c, i, nm, ni, inv, dig[10], num, aux;
    char sm[10], si[10], auxm[]="BBBBB00", auxi[]="ZZZ9999";
    while(scanf("%s %s %d", sm, si, &c) && sm[0]!='*')
    {
        nm=ni=inv=num=0;
        if(!isdigit(sm[3])) nm=1;
        if(isdigit(si[3]))
        {
            if(!isdigit(si[4])) inv=1;
        }
        else
        {
            if(isdigit(si[4])) inv=1;
            else ni=1;
        }
        if(ni==1)
        {
            for(i=0; i<5; i++)
                if(si[i]=='A' || si[i]=='C' || si[i]=='M' || si[i]=='I' || si[i]=='P')
                    inv=1;
        }
        if(inv==1) printf("N\n");
        else
        {
            if(nm==1 && ni==0) printf("N\n");
            else if(nm==0 && ni==1)
            {
                for(i=0; i<7; i++)
                {
                    dig[i]=auxi[i]-sm[i];
                    if(i==0) num+=26*260000*dig[i];
                    else if(i==1) num+=260000*dig[i];
                    else
                    {
                        aux=fast_exp(10, 6-i);
                        num+=dig[i]*aux;
                    }
                }
                num++;
                for(i=0; i<7; i++)
                {
                    if(si[i]>'C' && si[i]<'I') si[i]--;
                    else if(si[i]>'I' && si[i]<'M') si[i]-=2;
                    else if(si[i]>'M' && si[i]<'P') si[i]-=3;
                    else if(si[i]>'P') si[i]-=4;
                    dig[i]=si[i]-auxm[i];
                }
                for(i=0; i<7; i++)
                {
                    if(i==0) num+=21*21*21*2100*dig[i];
                    else if(i==1) num+=21*21*2100*dig[i];
                    else if(i==2) num+=21*2100*dig[i];
                    else if(i==3) num+=2100*dig[i];
                    else 
                    {
                        aux=fast_exp(10, 6-i);
                        num+=dig[i]*aux;
                    }
                }
                if(num<=0 || num>c) printf("N\n");
                else printf("Y\n");
            }
            else if(nm==1 && ni==1)
            {
                for(i=0; i<7; i++)
                {
                    if(si[i]>'C' && si[i]<'I') si[i]--;
                    else if(si[i]>'I' && si[i]<'M') si[i]-=2;
                    else if(si[i]>'M' && si[i]<'P') si[i]-=3;
                    else if(si[i]>'P') si[i]-=4;
                    if(sm[i]>'C' && sm[i]<'I') sm[i]--;
                    else if(sm[i]>'I' && sm[i]<'M') sm[i]-=2;
                    else if(sm[i]>'M' && sm[i]<'P') sm[i]-=3;
                    else if(sm[i]>'P') sm[i]-=4;
                    dig[i]=si[i]-sm[i];
                }
                for(i=0; i<7; i++)
                {
                    if(i==0) num+=21*21*21*2100*dig[i];
                    else if(i==1) num+=21*21*2100*dig[i];
                    else if(i==2) num+=21*2100*dig[i];
                    else if(i==3) num+=2100*dig[i];
                    else 
                    {
                        aux=fast_exp(10, 6-i);
                        num+=dig[i]*aux;
                    }
                }
                if(num<=0 || num>c) printf("N\n");
                else printf("Y\n");
            }
            else
            {
                for(i=0; i<7; i++)
                {
                    dig[i]=si[i]-sm[i];
                    if(i==0) num+=26*260000*dig[i];
                    else if(i==1) num+=260000*dig[i];
                    else
                    {
                        aux=fast_exp(10, 6-i);
                        num+=dig[i]*aux;
                    }
                }
                if(num<=0 || num>c) printf("N\n");
                else printf("Y\n");
            }
        }
    }
    return 0;    
}
