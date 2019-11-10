#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, x[111111], y[111111];
set<pair<int, int> > up, down;

struct event {
   int x, y, id, e;
   event(int x, int y, int id, int e): x(x), y(y), id(id), e(e) {}
};

bool cmp(event a, event b)
{
   if(a.x!=b.x) return a.x<b.x;
   if(a.e!=b.e) return a.e<b.e;
   if(!a.e) return a.id>b.id;
   return a.id<b.id;
}

int check(int p)
{
   if(up.empty() || down.empty()) return 1;
   int yup=(*up.begin()).first, ydown=-(*down.begin()).first;
   if(yup-p-1<=ydown+p) return 0;
   return 1;
}

int valid(int p)
{
   int i, flag=0;
   vector<event> v;
   up.clear();
   down.clear();
   v.push_back(event(-p-1, 0, -1, 0));
   v.push_back(event(p, 0, -1, 1));
   for(i=0; i<n; i++)
   {
       v.push_back(event(x[i]-p-1, y[i], i, 0));
       v.push_back(event(x[i]+p, y[i], i, 1));
   }
   sort(v.begin(), v.end(), cmp);
   for(i=0; i<v.size(); i++)
   {
       if(!v[i].e)
       {
           if(v[i].id==-1) flag=1;
           else
           {
               if(v[i].y>=0) up.insert(make_pair(v[i].y, v[i].id));
               if(v[i].y<=0) down.insert(make_pair(-v[i].y, v[i].id));
           }
           if(flag && check(p)) return 1;
       }
       else
       {
           if(v[i].id==-1) flag=0;
           else
           {
               if(v[i].y>=0) up.erase(make_pair(v[i].y, v[i].id));
               if(v[i].y<=0) down.erase(make_pair(-v[i].y, v[i].id));
               if(flag && check(p)) return 1;
           }
       }
   }
   return 0;
}

int main()
{
   int i, t=1, lo, mid, hi;
   while(scanf("%d", &n) && n>=0)
   {
       for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
       lo=0, hi=1000002;
       while(lo<hi)
       {
           mid=(lo+hi)/2;
           if(valid(mid)) lo=mid+1;
           else hi=mid;
       }
       printf("Case %d: ", t++);
       if(lo>1000000) printf("never\n");
       else printf("%d\n", lo);
   }
   return 0;
}
