#include <cstdio>
#include <vector>

using namespace std;

int f[1111];
vector<int> cycle[1111];

int main()
{
    int i, n, cur;
    long long r;
    while(scanf("%d %lld", &n, &r)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d", &f[i]);
            cycle[i].clear();
        }
        for(i=1; i<=n; i++)
        {
            cur=i;
            cycle[i].push_back(i);
            while(f[cur]!=i)
            {
                cycle[i].push_back(f[cur]);
                cur=f[cur];
            }
        }
        printf("%d", cycle[1][r%(int)cycle[1].size()]);
        for(i=2; i<=n; i++) printf(" %d", cycle[i][r%(int)cycle[i].size()]);
        printf("\n");
    }
    return 0;
}
