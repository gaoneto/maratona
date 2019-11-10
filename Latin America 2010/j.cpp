#include <stdio.h>

int main()
{
    int cartas[5], i, min, med, max, minp, maxp, cont, resp;
    while(scanf("%d %d %d %d %d", &cartas[0], &cartas[1], &cartas[2], &cartas[3], &cartas[4])==5 && cartas[0])
    {
        min=53;
        max=0;
        for(i=0; i<3; i++)
        {
            if(cartas[i]>max)
                max=cartas[i];
            if(cartas[i]<min)
                min=cartas[i];
        }
        for(i=0; i<3; i++)
        {
            if(cartas[i]!=max && cartas[i]!=min)
            {
                med=cartas[i];
                break;
            }
        }
        if(cartas[3]>cartas[4])
        {
            maxp=cartas[3];
            minp=cartas[4];
        }
        else 
        {
            minp=cartas[3];
            maxp=cartas[4];
        }
        if(maxp<min)
            resp=-1;
        else
        {
            if(minp>max)
                resp=1;
            else
            {
                if(minp>med)
                    resp=med+1;
                else
                {
                    if(minp>min)
                    {
                        if(maxp<max)
                            resp=-1;
                        else
                            resp=max+1;
                    }
                    else
                    {
                        if(maxp>max)
                            resp=max+1;
                        else
                            resp=-1;
                    }
                }
            }
        }
        while(resp==min || resp==med || resp==max || resp==minp || resp==maxp)
            resp++;
        if(resp==53)
            resp=-1;
        printf("%d\n", resp);
    }
    return 0;
}
