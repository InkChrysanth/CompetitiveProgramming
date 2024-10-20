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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> col(n+1);
    vector<vector<pll>> g(n+1);
    vector<vector<ll>> dist(n+1, vector<ll>(n+1));
    for(int i=1; i<=n; i++) cin>>col[i];
    for(int i=1; i<=n-1; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    }
    function<void(int, int, int, ll)> dfs=[&](int s, int u, int fa, ll mx)
    {
        dist[s][u]=mx;
        each(t, g[u]) if(t.fi!=fa)
        {
            ll v=t.fi, w=t.se;
            dfs(s, v, u, max(mx, w));
        }
    };
    for(int i=1; i<=n; i++)
        dfs(i, i, 0, 0);
    ll sum=0;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(col[i]^col[j])
                sum+=dist[i][j];
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ll res=sum;
        for(int j=1; j<=n; j++)
            res+=(col[i]^col[j] ? -dist[i][j] : dist[i][j]);
        cmax(ans, res);
    }
    cout<<ans<<endl;
	return 0;
}
// graphs, dfs