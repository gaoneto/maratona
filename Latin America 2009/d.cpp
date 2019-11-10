#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<pair<string, char> > cl;

int main()
{
	int i, n, contx, conte, cont, max;
	char e, h[10];
	while(scanf("%d", &n) && n)
	{
		cont=contx=conte=max=0;
		for(i=0; i<n; i++)
		{
		    scanf("%s %c", h, &e);
		    if(e=='E') conte++;
		    else if(e=='X') contx++;
		    cl.push_back(make_pair(h, e));
		}
		sort(cl.begin(), cl.end());
		for(i=0; i<n; i++)
			if(cl[i].second=='?')
			{
				if(conte<=contx || conte<n/2) 
				{
					cl[i].second='E';
					conte++;
				}
				else 
				{
					cl[i].second='X';
					contx++;
				}
			}
		for(i=0; i<n; i++)
		{
			if(cl[i].second=='E')
			{
				cont++;
				if(cont>max)
				    max=cont;
			}
			else cont--;
		}
		printf("%d\n", max);
		cl.clear();
	}
	return 0;
}
