// Problem: 破译密码
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/217/
// Memory Limit: 64 MB
// Time Limit: 2000 ms

#include <bits/extc++.h>
#define int long long
using namespace std;
const int N=50010;
int primes[N], cnt;
int mobius[N], sum[N];
bool st[N];
void init(int n)
{
    mobius[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            mobius[i]=-1;
        }
        for(int j=0; primes[j]*i<=n; j++)
        {
            int t=primes[j]*i;
            st[t]=true;
            if(i%primes[j]==0)
            {
                mobius[t]=0;
                break;
            }
            mobius[t]=mobius[i]*-1;
        }
    }
    for(int i=1; i<=n; i++)
        sum[i]=sum[i-1]+mobius[i];
}
signed main()
{
    init(N-1);
    int t; cin>>t;
    while(t--)
    {
        int a, b, d; cin>>a>>b>>d;
        a/=d, b/=d;
        int n=min(a, b);
        int res=0;
        for(int l=1, r; l<=n; l=r+1)
        {
            r=min(n, min(a/(a/l), b/(b/l)));
            res+=(sum[r]-sum[l-1])*(a/l)*(b/l);
        }
        cout<<res<<endl;
    }
    return 0;
}