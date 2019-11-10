#include <stdio.h>

int main()
{
    int i, a, b, c, card[14], max, ind, c1;
    while(scanf("%d %d %d", &a, &b, &c) && (a || b || c))
    {
        memset(card, 0, sizeof(card));
        card[a]++;
        card[b]++;
        card[c]++;
        max=0;
        for(i=1; i<14; i++)
        {
            if(card[i]>max)
            {
                max=card[i];
                ind=i;
            }
            if(card[i]==1) c1=i;
        }
        if(max==3)
        {
            if(ind==13) printf("*\n");
            else printf("%d %d %d\n", ind+1, ind+1, ind+1);
        }
        else if(max==1) printf("1 1 2\n");
        else
        {
            if(ind==13)
            {
                if(c1==12) printf("1 1 1\n");
                else printf("%d 13 13\n", c1+1);
            }
            else
            {
                if(c1>ind)
                {
                    if(c1==13) printf("1 %d %d\n", ind+1, ind+1);
                    else printf("%d %d %d\n", ind, ind, c1+1);
                }
                else if(ind==c1+1) printf("%d %d %d\n", ind, ind, c1+2);
                else printf("%d %d %d\n", c1+1, ind, ind);
            }
        }
    }
    return 0;
}
