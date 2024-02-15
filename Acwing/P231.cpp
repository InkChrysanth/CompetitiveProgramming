// Problem: 天码
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/233/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
#define int long long
using namespace std;
const int N=10010;
int n;
int a[N], tot[N];
int primes[N], cnt;
int mobius[N];
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
        for(int j=0; primes[j]<=n/i; j++)
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
}

int C(int n)
{
    return n*(n-1)*(n-2)*(n-3)/24;
}

signed main()
{
    init(N-1);
    while(cin>>n)
    {
        memset(tot, 0, sizeof tot);
        for(int i=1; i<=n; i++) cin>>a[i];
        int maxx=-1;
        for(int i=1; i<=n; i++)
        {
            maxx=max(maxx, a[i]);
            for(int j=1; j<=a[i]/j; j++)
            {
                if(a[i]%j==0)
                {
                    tot[j]++;
                    if(j*j!=a[i]) tot[a[i]/j]++;
                }
            }
        }
        int res=0;
        for(int i=1; i<=maxx; i++)
            res+=mobius[i]*C(tot[i]);
        cout<<res<<endl;
    }
    return 0;
}