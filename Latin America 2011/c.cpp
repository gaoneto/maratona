#include <stdio.h>
#include <iostream>
#define MAX 100100

using namespace std;

long long v[MAX];

int main()
{
    int i, k;
	long long f, sum, resp, j, c, r, m, l;
	while(scanf ("%lld", &f) && f)
	{
		sum=resp=0;
		for(i=0; i<f; i++)
		{
			scanf("%lld", &v[i]);
			sum+=v[i];
		}
		for(j=f; j*j<=sum; j++)
		{
			if(sum%j==0)
			{
				if (j%f==0)
				{
					c=j;
					r=v[0]%c;
					m=v[0];
					for(k=0; k<f; k++)
					{
						m=min(m, v[k]);
						if(v[k]%c!=r)
						{
							r=v[k]%c;
							break;
						}
					}
					if(r==(v[0]%c))
					{
                        r+=(r == 0)*c;
                        l=c/f;
                        if(r%l==0) resp+=((m-r)/c);
                    }
				}
                if(j*j!=sum && (sum/j)%f==0)
                {
                    c=sum/j;
                    r=v[0]%c;
                    m=v[0];
                    for(k=0; k<f; k++)
                    {
                        m=min(m, v[k]);
                        if(v[k]%c!=r)
                        {
                            r=v[k]%c;
                            break;
                        }
                    }
                    if(r!=(v[0]%c)) continue;
                    r+=(r == 0)*c;
                    l=c/f;
                    if(r%l!=0) continue;
                    resp+=((m-r)/c);
                }
			}
		}
		printf("%lld\n", resp);
	}
	return 0;
}
