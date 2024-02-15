// Problem: 新NIM游戏
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/231/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
#define int long long
using namespace std;
const int N=110;
int n, w[N];
signed main()
{
    cin>>n;
    int res=0;
    for(int i=1; i<=n; i++)
        cin>>w[i];
    sort(w+1, w+n+1, greater<int>());
    vector<int> d;
    for(int i=1; i<=n; i++)
    {
        int t=w[i];
        for(auto j: d) t=min(t, j^t);
        if(!t) res+=w[i];
        else d.push_back(t);
    }
    cout<<res<<endl;
    return 0;
}