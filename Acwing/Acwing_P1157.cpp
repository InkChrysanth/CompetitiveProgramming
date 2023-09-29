#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=300010, M=N*2;
int n, ans;
int h[N], e[M], ne[M], idx;
int sz[N], p[N], f[N][20], backup[N][20];
void add(int a, int b)
{
    e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

void sum(int u, int son)
{
    f[u][0]=son;
    for(int i=1; i<20; i++)
        f[u][i]=f[f[u][i-1]][i-1];
}

void getans(int u)
{
    int tot=sz[u];
    for(int k=19; k>=0; k--)
        if(f[u][k] && tot-sz[f[u][k]]<=tot/2)//自下而上
            u=f[u][k];
    ans+=u;
    if(!(tot%2) && sz[u]==tot/2) ans+=p[u];
}

void dfs1(int u, int fa)
{
    int son=0;
    sz[u]=1, p[u]=fa;
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;
        dfs1(j, u);
        sz[u]+=sz[j];
        if(sz[j]>sz[son]) son=j;
    }
    sum(u, son);
}

void dfs2(int u, int fa)
{
    int t1=0, t2=0, tsz=sz[u];
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(sz[j]>=sz[t1]) t2=t1, t1=j;
        else if(sz[j]>sz[t2]) t2=j;
    }
    for(int i=h[u]; ~i; i=ne[i])
    {
        int j=e[i];
        if(j==fa) continue;//递归时防止回搜
        getans(j); 
        p[u]=j, sz[u]=n-sz[j];
        if(j!=t1) sum(u, t1);
        else sum(u, t2);
        getans(u);
        dfs2(j, u);
    }
    p[u]=fa,  sz[u]=tsz;
    memcpy(f[u], backup[u], sizeof f[u]);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin>>T;
    while(T--)
    {
        cin>>n;
        memset(h, -1, sizeof h); idx=0;
        for(int i=1; i<=n-1; i++)
        {
            int a, b; cin>>a>>b;
            add(a, b), add(b, a);
        }
        dfs1(1, -1);
        ans=0;
        memcpy(backup, f, sizeof backup);
        dfs2(1, -1);
        cout<<ans<<endl;
    }
    return 0;
}