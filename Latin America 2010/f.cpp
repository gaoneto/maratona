#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char pal[2000];
    int i, vet[1000], aux, cont;
    do
    {
        gets(pal);
        if(pal[0]!='*')
        {
            aux=cont=0;
            for(i=0; i<strlen(pal); i++)
            {
                if(isupper(pal[i]))
                    pal[i]=tolower(pal[i]);
                if(isspace(pal[i]))
                    vet[aux++]=i;
            }
            for(i=0; i<aux; i++)
                if(pal[0]==pal[vet[i]+1])
                    cont++;
            if(cont==aux)
                printf("Y\n");
            else printf("N\n");
        }
    }while(pal[0]!='*');
    return 0;
}
