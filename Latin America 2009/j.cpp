#include <stdio.h>
#include <string.h>

int main()
{
    char jin[2000];
    float  duracao[2000], x;
    int i, resp;
    do
    {
        gets(jin);
        if(jin[0]!='*')
        {
            x=resp=0;
            for(i=1; i<strlen(jin); i++)
            {
                if(jin[i]=='/') duracao[i]=0;
                else if(jin[i]=='W') duracao[i]=1;
                else if(jin[i]=='H') duracao[i]=0.5;
                else if(jin[i]=='Q') duracao[i]=0.25;
                else if(jin[i]=='E') duracao[i]=0.125;
                else if(jin[i]=='S') duracao[i]=0.0625;
                else if(jin[i]=='T') duracao[i]=0.03125;
                else duracao[i]=0.015625;
            }
            for(i=1; i<strlen(jin); i++)
            {
                x+=duracao[i];
                if(duracao[i]==0)
                {
                    if(x==1)
                        resp++;
                    x=0;
                }
            }
            printf("%d\n", resp);
        }
    }while(jin[0]!='*');
    return 0;    
}
