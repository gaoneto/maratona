#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

map<int, string> b;
map<string, int> bi;
string s[10], resp[105];

int main()
{
    int i, j, d, size;
    char m[2], dec[200];
    s[1]="*.....", s[2]="*.*...", s[3]="**....", s[4]="**.*..", s[5]="*..*..";
    s[6]="***...", s[7]="****..", s[8]="*.**..", s[9]=".**...", s[0]=".***..";
    for(i=0; i<10; i++)
    {
        b[i]=s[i];
        bi[s[i]]=i;
    }
    while(scanf("%d", &d) && d)
    {
        scanf("%s", m);
        if(m[0]=='S')
        {
            scanf("%s", dec);
            size=strlen(dec);
            for(i=0; i<size; i++)
                resp[i]=b[dec[i]-'0'];
            for(j=0; j<6; j+=2)
            {
                for(i=0; i<size; i++)
                {
                    cout << resp[i][j] << resp[i][j+1];
                    if(i!=size-1) printf(" ");
                }
                printf("\n");
            }
        }
        else
        {
            for(j=0; j<6; j+=2)
                for(i=0; i<d; i++)
                    cin >> resp[i][j] >> resp[i][j+1];
            for(i=0; i<d; i++)
                printf("%d", bi[resp[i]]);
            printf("\n");
        }
    }
    return 0;
}
