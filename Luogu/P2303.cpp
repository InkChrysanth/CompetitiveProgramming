#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
int phi(int x)
{
    int res=x;
    for(int i=2; i<=x/i; i++)
    {
        if(x%i==0) res=res/i*(i-1);
        while(x%i==0) x/=i;
    }
    if(x>1) res=res/x*(x-1);
    return res;
}
signed main()
{
    cin>>n;
    for(int i=1; i<=n/i; i++)
    {
        if(n%i) continue;
        ans+=i*phi(n/i);
        if(i<n/i) ans+=n/i*phi(i);
    }
    cout<<ans<<endl;
    return 0;
}