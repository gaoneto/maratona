#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

int main()
{
    int t=1, T, N, M, K;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &N, &M, &K);
        if(N>M) swap(N, M);
        printf("Case #%d: %d %d %d ", t++, N, M, K);
        if(N<=2) printf("%d ", K);
        else if(N==3)
        {
            if(K<=4) printf("%d ", K);
            if(K==5) printf("4 ");
            if(K==6) printf("5 ");
            if(K==7) printf("6 ");
            if(K==8) printf("6 ");
            if(K==9) printf("7 ");
            if(K==10) printf("8 ");
            if(K==11) printf("8 ");
            if(K==12) printf("9 ");
            if(K==13) printf("10 ");
            if(K==14) printf("10 ");
            if(K==15) printf("11 ");
            if(K==16) printf("12 ");
            if(K==17) printf("13 ");
            if(K==18) printf("14 ");
        }
        else
        {
            if(K<=4) printf("%d ", K);
            if(K==5) printf("4 ");
            if(K==6) printf("5 ");
            if(K==7) printf("6 ");
            if(K==8) printf("6 ");
            if(K==9) printf("7 ");
            if(K==10) printf("8 ");
            if(K==11) printf("8 ");
            if(K==12) printf("8 ");
            if(K==13) printf("9 ");
            if(K==14) printf("9 ");
            if(K==15) printf("10 ");
            if(K==16) printf("10 ");
            if(K==17) printf("11 ");
            if(K==18) printf("12 ");
            if(K==19) printf("13 ");
            if(K==20) printf("14 ");
        }
        int S = N * M;
        int ans = K;
        for (int mask = 1; mask < (1 << S); mask++)
        {
            if (__builtin_popcount(mask) > K)
                continue;
            vector<vi> grid(N, vi(M));
            int empty = 0;
            queue<pii> q;
            for (int r = 0; r < N; r++)
                for (int c = 0; c < M; c++)
                {
                    int id = r * M + c;
                    if (mask & (1 << id))
                        grid[r][c] = 1;
                    else if (r == 0 || r == N - 1 || c == 0 || c == M - 1)
                    {
                        grid[r][c] = 2;
                        empty++;
                        q.push(pii(r, c));
                    }
                }
            while (!q.empty())
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    int r2 = r + dr[d];
                    int c2 = c + dc[d];
                    if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M && grid[r2][c2] == 0)
                    {
                        grid[r2][c2] = 2;
                        empty++;
                        q.push(pii(r2, c2));
                    }
                }
            }
            if (S - empty >= K)
                ans = min(ans, __builtin_popcount(mask));
        }
        printf("%d\n", ans);
    }
    return 0;
}
