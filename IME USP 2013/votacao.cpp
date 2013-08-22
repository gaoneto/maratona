#include <cstdio>
#include <algorithm>

using namespace std;

struct cand{
    int n, i;
    int v[111];
};

cand p[111];
int v, k;

bool cmp(struct cand a, struct cand b)
{
    if(a.n!=b.n) return a.n>b.n;
    for(int i=0; i<v; i++) if(a.v[i]!=b.v[i]) return a.v[i]>b.v[i];
    return a.i<b.i;
}

int main()
{
    int i, j, n, l;
    while(scanf("%d %d %d", &n, &k, &v)!=EOF)
    {
        for(i=0; i<k; i++)
        {
            p[i].n=0;
            p[i].i=i+1;
            for(j=0; j<v; j++) p[i].v[j]=0;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d", &l);
            for(j=0; j<l; j++)
            {
                int c;
                scanf("%d", &c);
                c--;
                if(c<0 || c>=k) continue;
                if(j>=v) continue;
                p[c].n++;
                p[c].v[j]++;
            }
        }
        sort(p, p+k, cmp);
        printf("%d", p[0].i);
        for(i=1; i<v; i++) printf(" %d", p[i].i);
        for(i=v; i<k; i++)
        {
            if(p[i].n!=p[i-1].n) break;
            for(j=0; j<v; j++) if(p[i].v[j]!=p[i-1].v[j]) break;
            if(j!=v) break;
            printf(" %d", p[i].i);
        }
        printf("\n");
    }
    return 0;
}
