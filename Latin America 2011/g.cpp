#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 2001
#define INF 1e9
#define EPS 1e-8

using namespace std;

typedef long long ll;

struct tree{
	int t, i, v, l, x, y;
	double a;
    tree() {}
	tree(int tt, int ii, int vv, int xx, int yy, double aa) { t=tt; i=ii; v=vv; x=xx; y=yy; a=aa; }
};

int ccw(int x1, int y1, int x2, int y2)
{
	ll l=(ll)x1*y2-(ll)y1*x2;
	if(l<0) return -1;
	return (l!=0);
}

int p, l, n, resp, s[2][2], cur;
tree a[MAX], aux[MAX];

bool compara(tree a, tree b)
{
    if(a.i==cur) return true;
    if(b.i==cur) return false;
	if(fabs(a.a-b.a)<EPS) return a.x<b.x;
	return a.a<b.a;
}

int main()
{
    int i, j, k, prod;
    double theta;
	while(scanf("%d %d", &p, &l) && (p || l))
    {
		n=p+l;
		resp=(int)INF;
		for(i=0; i<p; i++)
        {
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].v);
			a[i].t=0;
            a[i].i=i;
		}
		for(i=p; i<n; i++)
        {
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].v);
			a[i].t=1;
            a[i].i=i;
		}
		for(i=0; i<n; i++)
        {
            cur=i;
			for(j=0; j<n; j++)
            {
				theta=(a[j].x==a[i].x) ? INF : ((double)a[j].y-a[i].y)/((double)a[j].x-a[i].x);
				aux[j]=tree(a[j].t, j, a[j].v, a[j].x-a[i].x, a[j].y-a[i].y, theta);
			}
			memset(s, 0, sizeof(s));
			sort(aux, aux+n, compara);
			aux[1].l=0;
			for(j=2; j<n; j++)
            {
				prod=ccw(aux[1].x, aux[1].y, aux[j].x, aux[j].y);
				if(prod>0) aux[j].l=0;
				else if(prod<0) aux[j].l=1;
				else
                {
					if((aux[1].x!=0 && ((aux[1].x>0 && aux[j].x>0) || (aux[1].x<0 && aux[j].x<0))) ||
                       (aux[1].y!=0 && ((aux[1].y>0 && aux[j].y>0) || (aux[1].y<0 && aux[j].y<0)))) aux[j].l=0;
					else aux[j].l=1;
				}
			}
			for(j=1; j<n; j++) s[aux[j].t][aux[j].l]+=aux[j].v;
			resp=min(resp, min(s[0][1]+s[1][0], s[0][0]+s[1][1]));
			for(j=1; j<n; j++)
            {
				for(k=j; k<n && fabs(aux[j].a-aux[k].a)<EPS; k++)
                {
					s[aux[k].t][aux[k].l]-=aux[k].v;
					aux[k].l=(aux[k].l+1)%2;
					s[aux[k].t][aux[k].l]+=aux[k].v;
				}
				j=k-1;
			    resp=min(resp, min(s[0][1]+s[1][0], s[0][0]+s[1][1]));
			}
		}
		printf("%d\n", resp);
	}
	return 0;
}
