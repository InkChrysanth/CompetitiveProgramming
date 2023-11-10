// Problem: 排列计数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/232/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#pragma GCC optimize(2)
#include <bits/extc++.h>
#define int long long
using namespace std;
const int N=1000010, mod=1e9+7;
int fact[N], infact[N], f[N], n, m;
inline int qmi(int a, int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}
void init()
{
    f[0]=1, f[1]=0, f[2]=1;
    fact[0]=infact[0]=fact[1]=infact[1]=1;
    for(int i=2; i<N; i++)
    {
        f[i]=(f[i-1]+f[i-2])%mod*(i-1)%mod;
        fact[i]=fact[i-1]*i%mod;
        infact[i]=qmi(fact[i], mod-2);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<fact[n]*infact[n-m]%mod*infact[m]%mod*f[n-m]%mod<<endl;
    }
    return 0;
}