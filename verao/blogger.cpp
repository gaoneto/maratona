#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define INF 1e9

using namespace std;

const int N=1e5+10;

struct interval {
    int q, m, M, l, r, flip;
    interval(int m=INF, int M=-1, int q=0, int flip=0): m(m), M(M), q(q), flip(flip) {}
};

interval M[4*N];
char s[N], t[11], aux[N], auxt[11];
int sz, szt;

interval join(interval i1, interval i2)
{
    interval ret;
    ret.m=min(i1.m, i2.m), ret.M=max(i1.M, i2.M);
    ret.l=i1.l, ret.r=i2.r;
    for(int i=max(i1.l, i1.r-szt+2); i<=i1.r; i++)
    {
        int j=i+szt-1;
        if(j>i2.r) break;
        if(!strncmp(auxt, aux+i, szt))
        {
            int mis=0, flip;
            for(int k=0; k<szt; k++)
            {
                if(i+k<=i1.r) flip=i1.flip;
                else flip=i2.flip;
                if((s[i+k]!=t[k] && !flip) || (s[i+k]==t[k] && flip)) mis++;
            }
            ret.m=min(min(ret.m, mis), min(i1.m, i2.m));
            ret.M=max(max(ret.M, mis), max(i1.M, i2.M));
        }
    }
    return ret;
}

void push(int node, int b, int e)
{
    if(M[node].q%2==1)
    {
        if(M[node].M!=-1)
        {
            int aux=M[node].M;
            M[node].M=szt-M[node].m;
            M[node].m=szt-aux;
        }
        M[node].flip=1-M[node].flip;
    }
    if(b!=e) M[2*node].q+=M[node].q, M[2*node+1].q+=M[node].q;
    M[node].q=0;
}

void init(int node, int b, int e)
{
    if(b==e)
    {
        if(sz==1 && tolower(s[b])==tolower(t[0]))
        {
            if(s[b]==t[0]) M[node].m=M[node].M=0;
            else M[node].m=M[node].M=1;
        }
        else M[node].m=INF, M[node].M=-1;
        M[node].l=M[node].r=b;
        M[node].flip=0;
    }
    else
    {
        int m=(b+e)/2;
        init(2*node, b, m);
        init(2*node+1, m+1, e);
        M[node]=join(M[2*node], M[2*node+1]);
    }
    M[node].q=0;
    //printf("%d %d %d %d\n", b, e, M[node].m, M[node].M);
}

interval query(int node, int b, int e, int i, int j)
{
    interval i1, i2;
    push(node, b, e);
    if(i>e || j<b)
    {
        i1.M=-INF;
        return i1;
    }
    if(b>=i && e<=j) return M[node];
    else
    {
        int m=(b+e)/2;
        i1=query(2*node, b, m, i, j);
        i2=query(2*node+1, m+1, e, i, j);
        //printf("i1 --- %d %d %d %d\n", b, m, i1.m, i1.M);
        //printf("i2 --- %d %d %d %d\n", m+1, e, i2.m, i2.M);
        if(i1.M==-INF) return i2;
        if(i2.M==-INF) return i1;
        interval ret=join(i1, i2);
        //printf("ret -- %d %d %d %d\n", b, e, ret.m, ret.M);
        return ret;
    }
}

void update(int node, int b, int e, int i, int j)
{
    push(node, b, e);
    if(i>e || j<b) return;
    if(b>=i && e<=j)
    {
        if(M[node].M!=-1)
        {
            int aux=M[node].M;
            M[node].M=szt-M[node].m;
            M[node].m=szt-aux;
        }
        M[node].flip=1-M[node].flip;
        if(b!=e) M[2*node].q++, M[2*node+1].q++;
        //printf("%d %d %d %d\n", b, e, M[node].m, M[node].M);
    }
    else
    {
        int m=(b+e)/2;
        update(2*node, b, m, i, j);
        update(2*node+1, m+1, e, i, j);
        M[node]=join(M[2*node], M[2*node+1]);
        //printf("%d %d %d %d\n", b, e, M[node].m, M[node].M);
    }
}

int main()
{
    int i, n, l, r;
    while(scanf("%d %s", &n, t)!=EOF)
    {
        scanf("%s", s);
        strcpy(aux, s), strcpy(auxt, t);
        sz=strlen(s), szt=strlen(t);
        for(i=0; i<sz; i++) aux[i]=tolower(aux[i]);
        for(i=0; i<szt; i++) auxt[i]=tolower(auxt[i]);
        init(1, 0, sz-1);
        for(i=0; i<n; i++)
        {
            scanf("%d %d", &l, &r);
            l--, r--;
            printf("%d\n", query(1, 0, sz-1, l, r).M);
            update(1, 0, sz-1, l, r);
        }
    }
    return 0;
}
