#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t=1, T, n, i, j, ord[11], sz[11], vis[33];
    char s[111][111];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int valid=1;
        vector<char> v[111];
        for(i=0; i<n; i++) 
        {
            memset(vis, 0, sizeof(vis));
            scanf("%s", s[i]);
            ord[i]=i;
            sz[i]=strlen(s[i]);
            v[i].push_back(s[i][0]);
            vis[s[i][0]-'a']=1;
            for(j=1; j<sz[i]; j++) if(s[i][j]!=s[i][j-1])
            {
                if(vis[s[i][j]-'a']) valid=0;
                else v[i].push_back(s[i][j]);
            }
        }
        int ans=0;
        if(valid)
        {
            do
            {
                int ok=1;
                memset(vis, 0, sizeof(vis));
                for(i=0; i<v[ord[0]].size(); i++) vis[v[ord[0]][i]-'a']=1;
                for(i=1; i<n && ok; i++)
                {
                    if(s[ord[i]][0]!=s[ord[i-1]][sz[ord[i-1]]-1])
                    {
                        if(vis[s[ord[i]][0]-'a']) ok=0;
                        else vis[s[ord[i]][0]-'a']=1;
                    }
                    for(j=0; j<v[ord[i]].size() && ok; j++) if(v[ord[i]][j]!=s[ord[i]][0])
                    {
                        if(vis[v[ord[i]][j]-'a']) ok=0;
                        vis[v[ord[i]][j]-'a']=1;
                    }
                }
                if(ok) ans++;
            }while(next_permutation(ord, ord+n));
        }
        printf("Case #%d: %d\n", t++, ans);
    }
    return 0;
}
