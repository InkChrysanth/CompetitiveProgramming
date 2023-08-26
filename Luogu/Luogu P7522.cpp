#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f;
signed main()
{
    int n; cin>>n;
    int maxx=-INF, minx=INF;
    int res=0;
    if(n==1)
    {
        int x; cin>>x;
        cout<<x<<endl;
        return 0;
    }
    while(n--)
    {
        int x; cin>>x;
        res+=abs(x);
        minx=min(x, minx);
        maxx=max(x, maxx);
    }
    cout<<res-abs(minx)-abs(maxx)+(maxx-minx);
    return 0;
}