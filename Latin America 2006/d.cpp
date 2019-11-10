#include <stdio.h>
#include <string.h>

int main()
{
    int i, size, n, flag, ind;
    char esq[5100], dir[5100], cima[5100], baixo[5100], reg[5100];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", reg);
        strcpy(esq, reg);
        strcpy(baixo, reg);
        strcpy(dir, reg);
        strcpy(cima, reg);
        size=strlen(reg);
        if(reg[size-1]=='p')
        {
            baixo[size-1]='s';
            dir[size-1]='q';
            cima[size-1]='s';
            esq[size-1]='q';
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='q')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='r')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(esq[i]=='p') esq[i]='q';
                else if(esq[i]=='q') esq[i]='p';
                else if(esq[i]=='r') esq[i]='s';
                else esq[i]='r';
            }
            if(flag==1) esq[ind]='p';
            else if(flag==2) esq[ind]='s';
            else strcpy(esq, "<none>");
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='r')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='s')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(cima[i]=='p') cima[i]='s';
                else if(cima[i]=='q') cima[i]='r';
                else if(cima[i]=='r') cima[i]='q';
                else cima[i]='p';
            }
            if(flag==1) cima[ind]='q';
            else if(flag==2) cima[ind]='p';
            else strcpy(cima, "<none>");
        }
        else if(reg[size-1]=='q')
        {
            esq[size-1]='p';
            baixo[size-1]='r';
            dir[size-1]='p';
            cima[size-1]='r';
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='p')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='s')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(dir[i]=='p') dir[i]='q';
                else if(dir[i]=='q') dir[i]='p';
                else if(dir[i]=='r') dir[i]='s';
                else dir[i]='r';
            }
            if(flag==1) dir[ind]='q';
            else if(flag==2) dir[ind]='r';
            else strcpy(dir, "<none>");
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='r')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='s')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(cima[i]=='p') cima[i]='s';
                else if(cima[i]=='q') cima[i]='r';
                else if(cima[i]=='r') cima[i]='q';
                else cima[i]='p';
            }
            if(flag==1) cima[ind]='q';
            else if(flag==2) cima[ind]='p';
            else strcpy(cima, "<none>");
        }
        else if(reg[size-1]=='r')
        {
            esq[size-1]='s';
            cima[size-1]='q';
            dir[size-1]='s';
            baixo[size-1]='q';
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='p')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='s')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(dir[i]=='p') dir[i]='q';
                else if(dir[i]=='q') dir[i]='p';
                else if(dir[i]=='r') dir[i]='s';
                else dir[i]='r';
            }
            if(flag==1) dir[ind]='q';
            else if(flag==2) dir[ind]='r';
            else strcpy(dir, "<none>");
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='p')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='q')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(baixo[i]=='p') baixo[i]='s';
                else if(baixo[i]=='q') baixo[i]='r';
                else if(baixo[i]=='r') baixo[i]='q';
                else baixo[i]='p';
            }
            if(flag==1) baixo[ind]='s';
            else if(flag==2) baixo[ind]='r';
            else strcpy(baixo, "<none>");
        }
        else
        {
            dir[size-1]='r';
            cima[size-1]='p';
            esq[size-1]='r';
            baixo[size-1]='p';
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='q')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='r')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(esq[i]=='p') esq[i]='q';
                else if(esq[i]=='q') esq[i]='p';
                else if(esq[i]=='r') esq[i]='s';
                else esq[i]='r';
            }
            if(flag==1) esq[ind]='p';
            else if(flag==2) esq[ind]='s';
            else strcpy(esq, "<none>");
            flag=0;
            for(i=size-2; i>=1; i--)
            {
                if(reg[i]=='p')
                {
                    flag=1;
                    ind=i;
                    break;
                }
                else if(reg[i]=='q')
                {
                    flag=2;
                    ind=i;
                    break;
                }
            }
            for(i=ind+1; i<size-1; i++)
            {
                if(baixo[i]=='p') baixo[i]='s';
                else if(baixo[i]=='q') baixo[i]='r';
                else if(baixo[i]=='r') baixo[i]='q';
                else baixo[i]='p';
            }
            if(flag==1) baixo[ind]='s';
            else if(flag==2) baixo[ind]='r';
            else strcpy(baixo, "<none>");
        }
        printf("%s %s %s %s\n", cima, baixo, esq, dir);
    }
    return 0;    
}
