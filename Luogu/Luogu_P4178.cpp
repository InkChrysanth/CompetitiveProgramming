// Problem: P4178 Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4178
// Memory Limit: 500 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int N=40010, M=2*N;
int n, k;
int all_node, ans, root;
int max_part[N], sz[N], dist[N];
int h[N], e[M], ne[M], w[M], idx;
bool vis[N];
int add(int a, int b, int c)
{
    w[idx]=c, e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}
void get_root(int u, int fa)
{
    max_part[u]=0, sz[u]=1; 
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa || vis[j]) continue;  
        get_root(j, u); 
        sz[u]+=sz[j]; 
        max_part[u]=max(max_part[u], sz[j]); 
    }
    max_part[u]=max(max_part[u], all_node-sz[u]); 
    if(max_part[u]<max_part[root]) root=u; 
}
void get_dist(int u, int fa, int W)
{
    dist[++dist[0]]=W;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa || vis[j]) continue;
        get_dist(j, u, W+w[i]);
    }
}
int cal(int u, int W)
{
    dist[0]=0;
    get_dist(u, 0, W);
    sort(dist+1, dist+dist[0]+1);
    int res=0;
    for(int l=1, r=dist[0]; l<r;)
    {
        if(dist[l]+dist[r]<=k) res+=r-l, l++;
        else r--;
    }
    return res;
}
void solve(int u)
{
    vis[u]=true;
    ans+=cal(u, 0);
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(vis[j]) continue;
        ans-=cal(j, w[i]);
        all_node=sz[j];
        root=0;
        get_root(j, u);
        solve(root);
    }
}
int main()
{
    cin>>n;
    idx=ans=0;
    memset(h, -1, sizeof h);
    memset(max_part, 0, sizeof max_part);
    memset(vis, false, sizeof vis);
    memset(sz, 0, sizeof sz);
    for(int i=1; i<n; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        add(a, b, c), add(b, a, c);
    }
    cin>>k;
    all_node=n, max_part[0]=n, root=0;
    get_root(1, 0);
    solve(root);
    cout<<ans<<endl;
    return 0;
}