#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#define MAXN 1020000
#define GetI() ( SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2 )

using namespace std;

char cult[1100];
string s;
int id[MAXN], len[10001], dis[MAXN], top[10001], ord, d[10001], grau[10001];
vector<int> grafo[10001];
int N, v[MAXN]; // tamanho da string atual e representacao em inteiros da string
int SA[MAXN], SAR[MAXN]; // suffix array e suffix array "reverso"
int LCP[MAXN]; // longest common prefix
const char FIRST_CHAR = 'a'; // primeiro char do alfabeto (tabela ASCII)
const char LAST_CHAR = 'z'; // ultimo char do alfabeto (tabela ASCII)
const int ALF = LAST_CHAR - FIRST_CHAR + 1; // tamanho do alfabeto
int CUR_ALF; // tamanho do alfabeto da string atual
vector<int> occ[ALF]; // occ[i] - posicoes em que o char i aparece

bool leq(int a1, int a2, int b1, int b2)
{
    return(a1<b1 || a1==b1 && a2<=b2);
}

bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
    return(a1<b1 || a1==b1 && leq(a2, a3, b2, b3));
}

static void radix_pass(int* a, int* b, int* r, int n, int K)
{
    int *c=new int[K+1], i, sum=0, t;
    for(i=0; i<=K; i++) c[i]=0;
    for(i=0; i<n; i++) c[r[a[i]]]++;
    for(i=0; i<=K; i++)
    {
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i=0; i<n; i++) b[c[r[a[i]]]++]=a[i];
    delete []c;
}

void suffix_array(int* s, int* SA, int n, int K)
{
    int i, j, p, t, k, n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2, *s12=new int[n02+3], *SA12=new int[n02+3], *s0=new int[n0], *SA0=new int[n0];
    int name=0, c0=-1, c1 =-1, c2=-1;
    for(i=0, j=0; i<n+(n0-n1); i++)
        if(i%3!=0)
            s12[j++]=i;
    s12[n02]=s12[n02+1]=s12[n02+2]=SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
    radix_pass(s12, SA12, s+2, n02, K);
    radix_pass(SA12, s12, s+1, n02, K);
    radix_pass(s12, SA12, s, n02, K);
    for(i=0; i<n02; i++)
    {
        if(s[SA12[i]]!=c0 || s[SA12[i]+1]!=c1 || s[SA12[i]+2]!=c2)
        {
            name++;
            c0=s[SA12[i]];
            c1=s[SA12[i]+1];
            c2=s[SA12[i]+2];
        }
        if(SA12[i]%3==1) s12[SA12[i]/3]=name;
        else s12[SA12[i]/3+n0]=name;
    }
    if(name<n02)
    {
        suffix_array(s12, SA12, n02, name);
        for(i=0; i<n02; i++) s12[SA12[i]]=i+1;
    }
    else
        for(i=0; i<n02; i++) SA12[s12[i]-1]=i;
    j=0;
    for(i=0; i<n02; i++)
        if(SA12[i]<n0)
            s0[j++]=3*SA12[i];
    radix_pass(s0, SA0, s, n0, K);
    for(p=0, t=n0-n1, k=0; k<n; k++)
    {
        i=GetI();
        j=SA0[p];
        if(SA12[t]<n0 ? leq(s[i], s12[SA12[t]+n0], s[j], s12[j/3]) : leq(s[i], s[i+1], s12[SA12[t]-n0+1], s[j], s[j+1], s12[j/3+n0]))
        {
            SA[k]=i;
            t++;
            if(t==n02)
                for(k++; p<n0; p++, k++)
                    SA[k]=SA0[p];
        }
        else
        {
            SA[k]=j;
            p++;
            if(p==n0)
                for(k++; t<n02; t++, k++)
                    SA[k]=GetI();
        }
    }
}

void initialize(const string & s)
{
    int cnt=1, i, j;
    memset(v, 0, (N+10)*sizeof(int));
    for(i=0; i<ALF; i++) occ[i].clear();
    for(i=0; i<N; i++) occ[s[i]-FIRST_CHAR].push_back(i);
    for(i=0; i<ALF; i++)
        if(!occ[i].empty())
        {
            for(j=0; j<occ[i].size(); j++)
                v[occ[i][j]]=cnt;
            cnt++;
        }
    CUR_ALF=cnt-1;
}

//LCP comparando termos i e i+1 (diferente da definição vista que compara os termos i e i-1)
void lcp(const string & s)
{
    int i, h=0, r;
    for(i=0; i<N; i++) SAR[SA[i]]=i;
    for(i=0; i<N; i++)
        if(SAR[i]+1<N)
        {
            r=SA[SAR[i]+1];
            while(r+h<N && i+h<N && s[r+h]==s[i+h]) h++;
            LCP[SAR[i]]=h;
            if(h>0) h--;
        }
}

int main()
{
    int i, j, n, size, u, w, dist;
    while(scanf("%d", &n) && n)
    {
        s="";
        N=0;
        for(i=0; i<n; i++)
        {
            scanf("%s", cult);
            s+=cult;
            size=strlen(cult);
            s+="#";
            grafo[i].clear();
            len[i]=size++;
            for(j=0; j<size; j++)
            {
                id[N]=i;
                dis[N++]=len[i]-j;
            }
            d[i]=grau[i]=0;
        }
        initialize(s);
        suffix_array(v, SA, N, CUR_ALF);
        lcp(s);
        for(i=n; i<N-1; i++)
            if(dis[SA[i]]==len[id[SA[i]]])
            {
                j=i;
                while(LCP[j]>=len[id[SA[i]]])
                {
                    grafo[id[SA[i]]].push_back(id[SA[j+1]]);
                    grau[id[SA[j+1]]]++;
                    j++;
                    if(j==N-1) break;
                }
                j=i-1;
                while(LCP[j]>=len[id[SA[i]]])
                {
                    grafo[id[SA[i]]].push_back(id[SA[j]]);
                    grau[id[SA[j]]]++;
                    j--;
                    if(j<=1) break;
                }
            }
        ord=dist=0;
        for(i=0; i<n; i++) if(!grau[i]) top[ord++]=i;
        for(i=0; i<n; i++)
        {
            u=top[i];
            for(j=0; j<grafo[u].size(); j++)
            {
                w=grafo[u][j];
                grau[w]--;
                if(!grau[w]) top[ord++]=w;
            }
        }
        for(i=0; i<n; i++)
        {
            u=top[i];
            size=grafo[u].size();
            for(j=0; j<size; j++)
            {
                w=grafo[u][j];
                if(d[w]<d[u]+1)
                {
                    d[w]=d[u]+1;
                    if(d[w]>dist) dist=d[w];
                }
            }
        }
        printf("%d\n", dist+1);
    }
    return 0;
}
