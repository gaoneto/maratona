#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

char g[11][11], s[11111];

int main()
{
    int i, j, r, c, t, T=1, vis[33];
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        scanf("%[^\n]", s);
        r=c=0;
        memset(vis, 0, sizeof(vis));
        vis['J'-'A']=1;
        for(i=0; s[i]; i++)
        {
            if(isalpha(s[i]) && !vis[toupper(s[i])-'A'])
            {
                vis[toupper(s[i])-'A']=1;
                g[r][c]=toupper(s[i]);
                if(c==4) r++, c=0;
                else c++;
            }
        }
        for(i=0; i<26; i++) if(!vis[i])
        {
            g[r][c]='A'+i;
            if(c==4) r++, c=0;
            else c++;
        }
        getchar();
        scanf("%[^\n]", s);
        string st="", ans="";
        for(i=0; s[i]; i++) if(isalpha(s[i])) st+=toupper(s[i]);
        char ch='A';
        for(i=0; i<st.size(); i+=2)
        {
            if(i==st.size()-1)
            {
                if(ch==st[i])
                {
                    if(ch=='Z') ch='A';
                    else if(ch=='I') ch='K';
                    else ch++;
                }
                st+=ch;
                if(ch=='Z') ch='A';
                else if(ch=='I') ch='K';
                else ch++;
            }
            if(st[i]==st[i+1])
            {
                if(ch==st[i])
                {
                    if(ch=='Z') ch='A';
                    else if(ch=='I') ch='K';
                    else ch++;
                }
                st.insert(st.begin()+i+1, ch);
                if(ch=='Z') ch='A';
                else if(ch=='I') ch='K';
                else ch++;
            }
            int r1, c1, r2, c2;
            char ch1, ch2;
            for(r=0; r<5; r++) for(c=0; c<5; c++)
            {
                if(st[i]==g[r][c]) r1=r, c1=c;
                if(st[i+1]==g[r][c]) r2=r, c2=c;
            }
            if(r1==r2)
            {
                ch1=g[r1][(c1+1)%5];
                ch2=g[r2][(c2+1)%5];
            }
            else if(c1==c2)
            {
                ch1=g[(r1+1)%5][c1];
                ch2=g[(r2+1)%5][c2];
            }
            else
            {
                ch1=g[r1][c2];
                ch2=g[r2][c1];
            }
            ans+=ch1;
            ans+=ch2;
        }
        printf("Case %d: %s\n", T++, ans.c_str());
    }
    return 0;
}
