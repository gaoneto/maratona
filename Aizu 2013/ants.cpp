#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, l, d[22], p[22], t, out[22];
    char c;
    while(scanf("%d %d", &n, &l) && (n || l))
    {
        int cnt=n, id=0;
        memset(out, 0, sizeof(out));
        for(i=0; i<n; i++)
        {
            scanf(" %c %d", &c, &p[i]);
            d[i]=(c=='L') ? 0 : 1;
        }
        for(t=0; cnt>0; t++)
        {
            for(i=0; i<n; i++) if(!out[i])
            {
                if(!d[i]) p[i]--;
                else p[i]++;
            }
            for(i=0; i<n; i++) if(!out[i])
            {
                for(j=i+1; j<n; j++) if(!out[j] && p[i]==p[j]) d[i]=1-d[i], d[j]=1-d[j];
                if(p[i]==l) out[i]=1, id=i, cnt--;
            }
            for(i=0; i<n; i++) if(!out[i] && !p[i]) out[i]=1, id=i, cnt--;
        }
        printf("%d %d\n", t, id+1);
    }
    return 0;
}
