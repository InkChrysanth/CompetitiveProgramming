#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
vector<pair<int, int>> g[N];
bool st[N];
int ans=0;
void dfs(int u, int cur)
{
    st[u]=true;
    ans=max(ans, cur);
    for(auto& t: g[u])
    {
        int tt=t.first;
        int len=t.second;
        if (!st[tt])
            dfs(tt, cur+len);
    }
    st[u]=false;
}

int main()
{
    int n, m; cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    for(int i=1; i<=n; i++)
        dfs(i, 0);
    cout<<ans<<endl;
    return 0;
}