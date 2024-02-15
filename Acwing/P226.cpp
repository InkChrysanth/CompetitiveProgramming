// Problem: 233矩阵
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/228/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
#define int long long
using namespace std;
const int N=12, mod=10000007;
int n, m;
int a[N][N], g[N];
void mul(int a[N][N], int b[N][N])
{
    static int res[N][N];
    memset(res, 0, sizeof res);
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=n+1; j++)
            for(int k=0; k<=n+1; k++)
                res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(a, res, sizeof res);
}

void qmi()
{
    int tmp[N][N]={0};
    for(int i=0; i<=n+1; i++)
        tmp[i][i]=1;
    int k=m;
    while(k)
    {
        if(k&1) mul(tmp, a);
        mul(a, a);
        k>>=1;
    }
    memcpy(a, tmp, sizeof tmp);
}
signed main()
{
    while(cin>>n>>m)
    {
        g[0]=23, g[n+1]=3;
        for(int i=1; i<=n; i++)
            cin>>g[i];
        memset(a, 0, sizeof a);
        for(int i=0; i<=n; i++)
        {
            a[i][0]=10, a[i][n+1]=1;
            for(int j=1; j<=i; j++) a[i][j]=1;
        }
        a[n+1][n+1]=1;
        qmi();
        int res[N]={0};
        for(int i=0; i<=n+1; i++)
            for(int k=0; k<=n+1; k++)
                res[i]=(res[i]+a[i][k]*g[k])%mod;
        cout<<res[n]<<endl;
    }
    return 0;
}