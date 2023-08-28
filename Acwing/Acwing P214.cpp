// Problem: Devu和鲜花
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/216/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
#define int long long
using namespace std;
const int N=22, mod=1e9+7;
int A[N];
int down=1;
inline int qmi(int a, int k, int p)
{
    int res=1;
    while(k)
    {
        if(k&1) res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}
inline int C(int a, int b)
{
    if(a<b) return 0;
    int up=1;
    for(int i=a; i>a-b; i--) up=i%mod*up%mod;
    return up*down%mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>A[i];
    for(int j=1; j<=n-1; j++)
        down=j*down%mod;
    down=qmi(down, mod-2, mod);
    int res=0;
    for(int i=0; i<1<<n; i++)
    {
        int a=m+n-1, b=n-1;
        int sign=1;
        for(int j=0; j<n; j++)
            if(i>>j&1)
            {
                sign*=-1;
                a-=(A[j]+1);
            }
        res=(res+C(a, b)*sign)%mod;
    }
    cout<<(res+mod)%mod<<endl;
    return 0;
}