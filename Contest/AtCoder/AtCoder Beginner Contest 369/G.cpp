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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010;

int n;
vector<pii> g[N];
ll dep[N], mx[N], son[N];
ll ans[N], tot=1;

void dfs(int u, int par)
{
    each(t, g[u])
    {
        int v=t.fi, w=t.se;
        if(v==par) continue;
        dep[v]=dep[u]+w;
        dfs(v, u);
        if(mx[u]<mx[v]+w) mx[u]=mx[v]+w, son[u]=v;
    }
}

void _dfs(int u, int par, int k)
{
    each(t, g[u])
    {
        int v=t.fi, w=t.se;
        if(v==par) continue;
        if(v==son[u])
        {
            ans[k]+=w;
            _dfs(v, u, k);
        }
        else
        {
            ans[++tot]=w;
            _dfs(v, u, tot);
        }
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n-1; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].eb(mp(v, w)); g[v].eb(mp(u, w));
    }
    dfs(1, 0);
    _dfs(1, 0, 1);
    sort(ans+1, ans+tot+1, greater<ll>());
    // for(int i=1; i<=tot; i++) cerr<<ans[i]<<" \n"[i==tot];
    for(int i=1; i<=tot; i++)
    {
        ans[i]+=ans[i-1];   
        cout<<ans[i]*2<<endl;
    }
    for(int i=tot+1; i<=n; i++)
        cout<<ans[tot]*2<<endl;
	return 0;
}
