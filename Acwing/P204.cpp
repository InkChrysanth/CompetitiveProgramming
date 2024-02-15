#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll __int128_t
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1, y=0;
        return a;
    }
    ll d=exgcd(b, a%b, y, x);
    y-=a/b*x;
    return d;
}
signed main()
{
    int n, a1, m1;
    cin>>n>>a1>>m1;
    int x=0;
    for(int i=1; i<n; i++)
    {
        int a2, m2;
        ll k1, k2;
        cin>>a2>>m2;
        ll d=exgcd(a1, a2, k1, k2);
        if((m2-m1)%d)
        {
            puts("-1");
            return 0;
        }
        k1*=(m2-m1)/d;
        ll t=a2/d;
        k1=(k1%t+t)%t;
        m1=(ll)k1*a1+m1;
        a1=(ll)a1*a2/d;
    }
    x=(m1%a1+a1)%a1;
    cout<<x<<endl;
    return 0;
}