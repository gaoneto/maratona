#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 500010

using namespace std;

typedef pair<int, int> pii;

struct event {
    int x, id, ev; //ev=0 -> start, ev=1 -> end
    event() {}
    event(int x, int id, int ev) : x(x), id(id), ev(ev) {}
};

bool cmp(event a, event b)
{
    if(a.x!=b.x) return a.x<b.x;
    if(a.ev!=b.ev) return a.ev<b.ev;
    return a.id<b.id;
}

set<int> s;
int m[MAX];
map<pii, int> M;
event e[2*MAX];

void update(int i)
{
    int x, y;
    if(s.size()==1) m[*s.begin()]+=(e[i].x-e[i-1].x);
    else if(s.size()==2)
    {
        x=*s.begin(), y=*(--s.end());
        if(x>y) swap(x, y);
        M[pii(x, y)]+=(e[i].x-e[i-1].x);
    }
}

int main()
{
    int i, n, a, b;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        e[2*i]=event(a, i, 0);
        e[2*i+1]=event(b, i, 1);
    }
    n*=2;
    sort(e, e+n, cmp);
    s.insert(e[0].id);
    for(i=1; i<n; i++)
    {
        if(e[i].ev)
        {
            update(i);
            s.erase(e[i].id);
        }
        else
        {
            update(i);
            s.insert(e[i].id);
        }
    }
    int ans=0;
    for(map<pii, int>::iterator it=M.begin(); it!=M.end(); it++) ans=max(ans, it->second+m[it->first.first]+m[it->first.second]);
    sort(m, m+n/2);
    reverse(m, m+n/2);
    ans=max(ans, m[0]+m[1]);
    printf("%d\n", ans);
    return 0;
}
