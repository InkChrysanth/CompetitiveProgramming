#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N=100010;
int n;
PII ds[N], dx[N];
vector<int> q;
LL arange(int a, int b)
{
    vector<PII> h;
    for(int i=0; i<n; i++)
        if(ds[i].x<=a && dx[i].x>=b)
            h.push_back({ds[i].y, dx[i].y});
    if(h.empty()) return 0;
    LL res=0;
    sort(h.begin(), h.end());
    int st=h[0].x, ed=h[0].y;
    for(int i=1; i<h.size(); i++)
        if(h[i].x<=ed) ed=max(ed, h[i].y);
        else
        {
            res+=ed-st;
            st=h[i].x, ed=h[i].y;
        }
    res+=ed-st;
    res*=b-a;
    return res;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        ds[i]={x1, y1}, dx[i]={x2, y2};
        q.push_back(x1), q.push_back(x2);
    }
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    LL res=0;
    for(int i=0; i<q.size()-1; i++)
        res+=arange(q[i], q[i+1]);
    cout<<res<<endl;
    return 0;
}
