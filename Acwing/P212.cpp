#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010, mod=1e9+9;
int n;
int p[N], fact[N];
bool st[N];
int qmi(int a, int k)
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
signed main()
{
    ios::sync_with_stdio(false);
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%mod;
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        memset(st, false, sizeof st);
        for(int i=1; i<=n; i++) cin>>p[i];
        int cnt=0, res=1;
        for(int i=1; i<=n; i++)
        {
            if(st[i]) continue;
            cnt++;
            int len=1;
            st[i]=true;
            for(int j=p[i]; j!=i; j=p[j]) st[j]=true, len++;
            res=res*(len==1 ? 1 : qmi(len, len-2))%mod;
            res=res*qmi(fact[len-1], mod-2)%mod;
        }
        res=res*fact[n-cnt]%mod;
        cout<<res<<endl;
    }
    return 0;
}