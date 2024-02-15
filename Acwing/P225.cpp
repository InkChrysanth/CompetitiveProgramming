// Problem: 矩阵幂求和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/227/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
using namespace std;
const int N=31;
int n, k, mod;
int e[N][N], ans[N][N];
void init(int a[N][N], bool state)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a[i][j]=(i==j) ? state : 0;
}

void add(int a[N][N], int b[N][N])
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a[i][j]=(a[i][j]+b[i][j])%mod;
}

void mul(int a[N][N], int b[N][N])
{
    static int res[N][N];
    init(res, false);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(a, res, sizeof res);
}

void qmi(int a[N][N], int k)
{
    static int res[N][N];
    init(res, true);
    while(k)
    {
        if(k&1) mul(res, a);
        mul(a, a);
        k>>=1;
    }
    memcpy(a, res, sizeof res);
}

void solve(int k)
{
    if(k==1) return;
    int tmp[N][N];
    memcpy(tmp, ans, sizeof ans);
    if(k&1)
    {
        solve(k-1);
        mul(ans, tmp);
        add(ans, tmp);    
    }
    else
    {
        solve(k/2);
        qmi(tmp, k/2);
        add(tmp, e);
        mul(ans, tmp);
    }
}

int main()
{
    cin>>n>>k>>mod;
    init(e, true);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>ans[i][j];
            ans[i][j]%=mod;
        }
    solve(k);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}