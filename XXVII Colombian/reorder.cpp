#include <cstdio>
#include <cstring>

using namespace std;

char s[2222], p[2222], pal[2222][2222];
int a[2222][27], b[27], sz[2222];

int main()
{
    int i, j, t, n, f;
    char * pch;
    scanf("%d", &t);
    while(t--)
    {
        n=f=0;
        memset(a, 0, sizeof(a));
        getchar();
        scanf("%[^\n]", s);
        getchar();
        scanf("%[^\n]", p);
        pch=strtok(s, " ");
        while(pch!=NULL)
        {
            strcpy(pal[n], pch);
            sz[n]=strlen(pal[n]);
            for(i=0; i<sz[n]; i++) a[n][pal[n][i]-'a']++;
            n++;
            pch=strtok(NULL, " ");
        }
        pch=strtok(p, " ");
        while(pch!=NULL)
        {
            memset(b, 0, sizeof(b));
            int size=strlen(pch);
            for(i=0; i<size; i++) b[pch[i]-'a']++;
            for(i=0; i<n; i++) if(pal[i][0]==pch[0] && pal[i][sz[i]-1]==pch[size-1])
            {
                for(j=0; j<27; j++) if(a[i][j]!=b[j]) break;
                if(j==27)
                {
                    strcpy(pch, pal[i]);
                    break;
                }
            }
            if(f) printf(" ");
            printf("%s", pch);
            f=1;
            pch=strtok(NULL, " ");
        }
        printf("\n");
    }
    return 0;
}
