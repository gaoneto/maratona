#include <stdio.h>

int esq[100010], dir[100010];

int main()
{
    int i, b, s, l, r;
    while(scanf("%d %d", &s, &b) && (s || b))
    {
        for(i=1; i<s+1; i++)
        {
            esq[i]=i-1;
            dir[i]=i+1;
        }
        for(i=0; i<b; i++)
        {
            scanf("%d %d", &l, &r);
            if(!esq[l]) printf("* ");
            else printf("%d ", esq[l]);
            if(dir[r]>s) printf("*\n");
            else printf("%d\n", dir[r]);
            dir[esq[l]]=dir[r];
            esq[dir[r]]=esq[l];
        }
        printf("-\n");
    }
    return 0;
}
