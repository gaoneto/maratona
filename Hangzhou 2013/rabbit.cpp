#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

int n, t[MAX], l[MAX], r[MAX], w[MAX], ans[MAX], pre[MAX];
vector<int> d[MAX];
vector<pair<int, int> > qu[MAX];

void update(int idx, int v) { for(; idx<=n; idx+=idx&-idx) t[idx]+=v; }

int query(int idx)
{
    int sum=0;
    for(; idx>0; idx-=idx&-idx) sum+=t[idx];
    return sum;
}

void process()
{
    int i, j, left, right, v;
    memset(pre, -1, sizeof(pre));
    for(i=1; i<=n; i++)
    {
        left=1;
        for(j=0; j<d[w[i]].size(); j++)
        {
            v=d[w[i]][j];
            if(pre[v]!=-1) left=max(left, pre[v]+1);
            pre[v]=i;
        }
        l[i]=left;
    }
    memset(pre, -1, sizeof(pre));
    for(i=n; i>=1; i--)
    {
        right=n;
        for(j=0; j<d[w[i]].size(); j++)
        {
            v=d[w[i]][j];
            if(pre[v]!=-1) right=min(right, pre[v]-1);
            pre[v]=i;
        }
        r[i]=right;
    }
}

void solve()
{
    int i, j, left, right, u;
    priority_queue<pair<int, int> > q;
    for(i=1; i<=n; i++)
    {
        update(i, 1);
        left=l[i]-1;
        if(left) update(left, -1);
        while(!q.empty())
        {
            left=q.top().second;
            right=-q.top().first;
            if(right==i)
            {
                q.pop();
                update(left, -1);
                left=l[left]-1;
                if(left) update(left, 1);
            }
            else break;
        }
        right=r[i]+1;
        if(right<=n) q.push(make_pair(-right, i));
        for(j=0; j<qu[i].size(); j++) ans[qu[i][j].second]=query(i)-query(qu[i][j].first-1);
    }
}

int main()
{
    int i, j, m, a, b;
    for(i=2; i<MAX; i++) for(j=i; j<MAX; j+=i) d[j].push_back(i);
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        memset(t, 0, sizeof(t));
        for(i=1; i<=n; i++) scanf("%d", &w[i]), qu[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            qu[b].push_back(make_pair(a, i));
        }
        process();
        solve();
        for(i=0; i<m; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
