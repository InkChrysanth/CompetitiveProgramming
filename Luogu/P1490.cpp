// Problem: P1490 买蛋糕
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1490
// Memory Limit: 125 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, cnt;
int dfs(int u, int sum, int max_sum)
{
    if(u+1==cnt)
    {
        if(sum*2+1>=n)
        {
            if(sum+max_sum+1>n) ans+=sum-max_sum+1;
            else ans+=sum*2+2-n;
        }
        return 0;
    }
    for(int i=max_sum+1; i<=sum+1; i++)
        dfs(u+1, sum+i, i);
}
signed main()
{
    cin>>n;
    for(int i=1; i<=n; i*=2) cnt++;
    dfs(0, 0, 0);
    cout<<cnt<<' '<<ans<<endl;
    return 0;
}