#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=21000, mod=998244353;
int f[M];
int n, m;
int qmi(int a, int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        k>>=1;
        a=a*a%mod;
    }
    return res;
}
  
signed main()
{
    cin>>n;
    m=n*(n+1)/2;
    f[0]=1;
    for(int i=1; i<=n; i++)
    {
        int k=i*(i-1)/2;
        for(int j=k; j>=0; j--)
            // use Fermat's little theorem
            f[j+i]=(f[j]+f[j+i])%(mod-1);
    }
    int res=1;
    for(int i=1; i<=m; i++)
        res=res*qmi(i, f[i])%mod;
    cout<<res<<endl;
    return 0;
}