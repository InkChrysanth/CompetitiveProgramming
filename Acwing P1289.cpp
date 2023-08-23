#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=200907;
int qmi(int a, int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=res*a%MOD;
        a=a*a%MOD;
        k>>=1;
    }
    return res;
}
signed main()
{
    int t; cin>>t;
    while(t--)
    {
        int a, b, c, k; cin>>a>>b>>c>>k;
        if(a+c==b*2) cout<<((b-a)*(k-1)%MOD+a)%MOD<<endl;
        else cout<<a*qmi(b/a, k-1)%MOD<<endl;
    }
    return 0;
}
