#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

int dx[12]={0, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 0};
int dy[12]={-1, -1, 0, 0, 1, 1, 1, 1, 0, 0, -1, -1};

int main()
{
    int i, n, j, k, flag=0, u, v, cont;
    char s[10][10];
    for(i=0; i<4; i++) scanf("%s", s[i]);
    for(i=0; i<4; i++) for(j=0; j<4; j++)
    {
        cont=1;
        for(k=0; k<12; k++)
        {
            u=i+dx[k];
            v=j+dy[k];
            if(u>=0 && u<4 && v>=0 && v<4 && s[i][j]==s[u][v]) cont++;
            if(k%3==2 && cont>=3) flag=1;
            if(k%3==2) cont=1;
        }
    }
    printf("%s", (flag) ? "YES" : "NO");
    return 0;
}
