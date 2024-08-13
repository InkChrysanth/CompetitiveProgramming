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
constexpr int N=100010;

int n;
vector<int> g[N];
ll sum, mx;
ll col[N], cnt[N], ans[N];
int sz[N], son[N];

void _dfs(int u, int par)
{
    sz[u]=1;
    each(v, g[u])
    {
        if(v==par) continue;
        _dfs(v, u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}

void modify(int u, int par, int val, int p)
{
    cnt[col[u]]+=val;
    if(cnt[col[u]]>mx) mx=cnt[col[u]], sum=col[u];
    else if(cnt[col[u]]==mx) sum+=col[u];
    each(v, g[u])
    {
        if(v==par || v==p) continue;
        modify(v, u, val, p);
    }
}

void dfs(int u, int par, bool keep)
{
    each(v, g[u])
    {
        if(v==par || v==son[u]) continue;
        dfs(v, u, false);
    }
    if(son[u]) dfs(son[u], u, true);
    modify(u, par, 1, son[u]);
    ans[u]=sum;
    if(keep==0) modify(u, par, -1, 0), sum=mx=0;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>col[i];
    for(int i=1, u, v; i<=n-1; i++)
    {
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    _dfs(1, 0);
    dfs(1, 0, false);
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<' ';
	return 0;
}
