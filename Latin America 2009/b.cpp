#include <stdio.h>

int h[105][105][105];

int main()
{
    int i, j, l, n, r, c, k;
    while(scanf("%d %d %d %d", &n, &r, &c, &k) && (n || r || c || k))
    {
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                scanf("%d", &h[0][i][j]);
        for(l=0; l<k; l++)
        {
            for(i=0; i<r; i++)
                for(j=0; j<c; j++)
                    h[l+1][i][j]=h[l][i][j];
            for(i=0; i<r; i++)
                for(j=0; j<c; j++)
                {
                    if(i==0)
                    {
                        if(j==0)
                        {
                            if(h[l][i][j+1]-h[l][i][j]==1 || h[l][i][j+1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j+1]=h[l][i][j];
                            }
                            if(h[l][i+1][j]-h[l][i][j]==1 || h[l][i+1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i+1][j]=h[l][i][j];
                            }
                        }
                        else if(j==c-1)
                        {
                            if(h[l][i][j-1]-h[l][i][j]==1 || h[l][i][j-1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j-1]=h[l][i][j];
                            }
                            if(h[l][i+1][j]-h[l][i][j]==1 || h[l][i+1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i+1][j]=h[l][i][j];
                            }
                        }
                        else
                        {
                            if(h[l][i][j-1]-h[l][i][j]==1 || h[l][i][j-1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j-1]=h[l][i][j];
                            }
                            if(h[l][i][j+1]-h[l][i][j]==1 || h[l][i][j+1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j+1]=h[l][i][j];
                            }
                            if(h[l][i+1][j]-h[l][i][j]==1 || h[l][i+1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i+1][j]=h[l][i][j];
                            }       
                        }
                    }
                    else if(i==r-1)
                    {
                        if(j==0)
                        {
                            if(h[l][i][j+1]-h[l][i][j]==1 || h[l][i][j+1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j+1]=h[l][i][j];
                            }
                            if(h[l][i-1][j]-h[l][i][j]==1 || h[l][i-1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i-1][j]=h[l][i][j];
                            }
                        }
                        else if(j==c-1)
                        {
                            if(h[l][i][j-1]-h[l][i][j]==1 || h[l][i][j-1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j-1]=h[l][i][j];
                            }
                            if(h[l][i-1][j]-h[l][i][j]==1 || h[l][i-1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i-1][j]=h[l][i][j];
                            }
                        }
                        else
                        {
                            if(h[l][i][j-1]-h[l][i][j]==1 || h[l][i][j-1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j-1]=h[l][i][j];
                            }
                            if(h[l][i][j+1]-h[l][i][j]==1 || h[l][i][j+1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j+1]=h[l][i][j];
                            }
                            if(h[l][i-1][j]-h[l][i][j]==1 || h[l][i-1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i-1][j]=h[l][i][j];
                            }       
                        }
                    }
                    else
                    {
                        if(j==0)
                        {
                            if(h[l][i][j+1]-h[l][i][j]==1 || h[l][i][j+1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j+1]=h[l][i][j];
                            }
                            if(h[l][i-1][j]-h[l][i][j]==1 || h[l][i-1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i-1][j]=h[l][i][j];
                            }
                            if(h[l][i+1][j]-h[l][i][j]==1 || h[l][i+1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i+1][j]=h[l][i][j];
                            }
                        }
                        else if(j==c-1)
                        {
                            if(h[l][i][j-1]-h[l][i][j]==1 || h[l][i][j-1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j-1]=h[l][i][j];
                            }
                            if(h[l][i-1][j]-h[l][i][j]==1 || h[l][i-1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i-1][j]=h[l][i][j];
                            }
                            if(h[l][i+1][j]-h[l][i][j]==1 || h[l][i+1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i+1][j]=h[l][i][j];
                            }
                        }
                        else
                        {
                            if(h[l][i][j-1]-h[l][i][j]==1 || h[l][i][j-1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j-1]=h[l][i][j];
                            }
                            if(h[l][i][j+1]-h[l][i][j]==1 || h[l][i][j+1]-h[l][i][j]==1-n)
                            {
                                h[l+1][i][j+1]=h[l][i][j];
                            }
                            if(h[l][i-1][j]-h[l][i][j]==1 || h[l][i-1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i-1][j]=h[l][i][j];
                            }
                            if(h[l][i+1][j]-h[l][i][j]==1 || h[l][i+1][j]-h[l][i][j]==1-n)
                            {
                                h[l+1][i+1][j]=h[l][i][j];
                            }       
                        }
                    }
                }
        }
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
                printf("%d ", h[k][i][j]);
            printf("\n");
        }
    }
    return 0;    
}
