#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

pair<int, int> v[2222];

int main()
{
    int i, j, n, m, k, c, resp, cont, f, down, up, t, x[1111], y[1111], r[1111];
    double mod, R;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        scanf("%d %d", &c, &k);
        resp=0;
        for(i=0; i<c; i++) scanf("%d %d %d", &x[i], &y[i], &r[i]);
        for(i=1; i<=n; i++)
        {
            t=0;
            for(j=0; j<c; j++)
            {
                mod=fabs(x[j]-i);
                if(mod>r[j]) continue;
                R=r[j];
                down=(int)(y[j]-sqrt(R*R-mod*mod)+1-1e-6);
                up=(int)(y[j]+sqrt(R*R-mod*mod));
                if(up<1 || down>m) continue;
                v[t++]=make_pair(max(1, down), -1);
                v[t++]=make_pair(min(m, up), 1);
            }
            sort(v, v+t);
            cont=down=0;
            for(j=0; j<t; j++)
            {
                if(v[j].second==-1)
                {
                    cont++;
                    if(cont==k) down=v[j].first;
                }
                else
                {
                    cont--;
                    if(cont<k && down)
                    {
                        resp+=(v[j].first-down+1);
                        down=0;
                    }
                }
            }
            if(cont>=k && down) resp+=(v[t-1].first-down+1);
        }
        printf("%d\n", resp);
    }
    return 0;
}
