// Problem: 绿豆蛙的归宿
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/219/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
using namespace std;
const int N=100010, M=200010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dout[N];
double f[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
double dp(int u)
{
    if(f[u]>=0) return f[u];
    f[u]=0;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        f[u]+=(w[i]+dp(j))/dout[u];
    }
    return f[u];
}
int main()
{
    memset(h, -1, sizeof h);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        add(a, b, c);
        dout[a]++;
    }
    memset(f, -1, sizeof f);
    printf("%.2lf", dp(1));
    return 0;
}