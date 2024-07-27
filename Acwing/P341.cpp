#include <bits/stdc++.h>
using namespace std;
const int N=100010, INF=0x3f3f3f3f;
int n, m;
int mins[N], maxs[N], w[N];
vector<int> g[N];
vector<int> rg[N];
void dfs_min(int u, int value)
{
    if(value>=mins[u]) return;
    value=min(value, w[u]);
    mins[u]=value;
    for(auto v: g[u]) dfs_min(v, value);
}
void dfs_max(int u, int value)
{
    if(value<=maxs[u]) return;
    value=max(value, w[u]);
    maxs[u]=value;
    for(auto v: rg[u]) dfs_max(v, value);
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>w[i], mins[i]=INF, maxs[i]=-INF;
    while(m--)
    {
        int a, b, type; cin>>a>>b>>type;
        g[a].push_back(b), rg[b].push_back(a);
        if(type==2) g[b].push_back(a), rg[a].push_back(b);
    }
    dfs_min(1, w[1]);
    dfs_max(n, w[n]);
    int ans=-INF;
    for(int i=1; i<=n; i++)
        ans=max(ans, maxs[i]-mins[i]);
    cout<<ans<<endl;
    return 0;
}
