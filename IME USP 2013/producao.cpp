#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int d, p, n;
    vector <pair<int,int> > v;
    while(scanf("%d", &n) != EOF)
    {
        v.clear();
        for(int i=0;i<n;i++)
        {
            cin >> d >> p;
            v.push_back(make_pair(d,p));
        }
        sort(v.begin(),v.end());
        int pt=0;
        int t=1;
        queue <int> q;
        while(1)
        {
            if(q.empty() && pt >= n) break;
            while(pt < n && v[pt].first <= t) q.push(v[pt++].second);
            if(q.empty())
            {
                t = v[pt].first;
                continue;
            }
            t += q.front();
            q.pop();
        }
        cout << t << endl;
    }
    return 0;
}
