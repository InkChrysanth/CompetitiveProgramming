//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010, K=21;

int n, m, tot;
vector<int> g[N];
int dep[N], ans[N], fa[N][K];

#define ls(x) tr[x].l
#define rs(x) tr[x].r
struct Node{ int l, r, id, cnt; } tr[N<<6];

void pushup(int u)
{
    tr[u].cnt=0;
    if(ls(u) && tr[u].cnt<tr[ls(u)].cnt) tr[u].id=tr[ls(u)].id, tr[u].cnt=tr[ls(u)].cnt;
    if(rs(u) && tr[u].cnt<tr[rs(u)].cnt) tr[u].id=tr[rs(u)].id, tr[u].cnt=tr[rs(u)].cnt;
}

void modify(int u, int l, int r, int pos, int val)
{
    if(!u) return;
    if(l==r)
    {
        tr[u].id=pos, tr[u].cnt+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) modify((ls(u) ? ls(u) : ls(u)=++tot), l, mid, pos, val);
    else modify((rs(u) ? rs(u) : rs(u)=++tot), mid+1, r, pos, val);
    pushup(u);
}

int merge(int x, int y, int l, int r)
{
    if(!x || !y) return x+y;
    if(l==r)
    {
        tr[y].id=x, tr[x].cnt+=tr[y].cnt;
        return x;
    }
    int mid=(l+r)>>1;
    ls(x)=merge(ls(x), ls(y), l, mid);
    rs(x)=merge(rs(x), rs(y), mid+1, r);
    pushup(x);
    return x;
}

void _dfs(int u, int par)
{
    fa[u][0]=par;
    dep[u]=dep[par]+1;
    for(int k=1; k<K; k++)
        fa[u][k]=fa[fa[u][k-1]][k-1];
    each(v, g[u])
    {
        if(v==par) continue;
        _dfs(v, u);
    }
}

int lca(int x, int y)
{
    if(dep[x]<dep[y]) swap(x, y);
    for(int k=K-1; k>=0; k--)
        if(dep[fa[x][k]]>=dep[y])
            x=fa[x][k];
    if(x==y) return x;
    for(int k=K-1; k>=0; k--)
        if(fa[x][k]!=fa[y][k])
            x=fa[x][k], y=fa[y][k];
    return fa[x][0];
}

void dfs(int u, int par)
{
    each(v, g[u])
    {
        if(v==par) continue;
        dfs(v, u);
        merge(u, v, 1, N);
    }
    ans[u]=tr[u].id;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m; tot=n;
    for(int i=1, u, v; i<n; i++)
    {
        cin>>u>>v;
        g[u].eb(v), g[v].eb(u);
    }
    _dfs(1, 0);
    for(int i=1, a, b, c; i<=m; i++)
    {
        cin>>a>>b>>c;
        int _lca=lca(a, b);
        modify(a, 1, N, c, 1);
        modify(b, 1, N, c, 1);
        modify(_lca, 1, N, c, -1);
        modify(fa[_lca][0], 1, N, c, -1);
    }
    dfs(1, 0);
    for(int i=1; i<=n; i++) cout<<ans[i]<<endl;
	return 0;
}
