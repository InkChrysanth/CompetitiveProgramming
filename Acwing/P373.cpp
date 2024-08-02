#include <bits/stdc++.h>
using namespace std;
constexpr int N=210;

int n, m, k;
int match[N];
bool st[N], g[N][N];

int dfs(int u)
{
    for(int i=1; i<=m; i++)
    {
        if(st[i] || g[u][i]) continue;
        st[i]=1;
        if(!match[i] || dfs(match[i]))
        {
            match[i]=u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++)
    {
        int x, y; cin>>x>>y;
        g[x][y]=1;
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        memset(st, 0, sizeof st);
        ans+=dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}