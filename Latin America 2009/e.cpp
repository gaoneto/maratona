#include <stdio.h>
#define INF 2000000000

int c[4]={2, 3, 5, 7};
int p[4]={100, 9900, 990000, INF};

int consumo(int preco)
{
    int con=0, i=0;
    while(preco>0)
    {
        if(preco>=c[i]*p[i])
        {
            preco-=c[i]*p[i];
            con+=p[i];
            i++;
        }
        else
        {
            con+=preco/c[i];
            preco=0;
        }
    }
    return con;
}

int preco(int consumo)
{
    int pre=0, i=0;
    while(consumo>0)
    {
        if(consumo>=p[i])
        {
            pre+=c[i]*p[i];
            consumo-=p[i];
            i++;
        }
        else
        {
            pre+=consumo*c[i];
            consumo=0;
        }
    }
    return pre;
}

int main()
{
    int a, b, ini, fim, mid, v, meu, viz;
    while(scanf("%d %d", &a, &b) && (a || b))
    {
        ini=0;
        fim=consumo(a);
        v=fim;
        mid=(ini+fim)/2;
        while(ini<fim)
        {
            meu=preco(mid);
            viz=preco(v-mid);
            if(meu-viz<b) ini=mid;
            else if(meu-viz==b)
            {
                ini=mid;
                break;
            }
            else fim=mid;
            mid=(ini+fim)/2;
        }
        printf("%d\n", preco(v-ini));
    }
}
