//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".ans")
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

signed main()
{
    // Fre("apple");
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);    
    for(int i=1, u, v; i<=n-1; i++)
    {
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    vector<int> f(n+1, 0), g(n+1, 0);
    function<void(int, int)> _dfs=[&](int u, int fa)
    {
        each(v, adj[u])
        {
            if(v==fa) continue;
            _dfs(v, u);
            if(f[v]+1>f[u])
            {
                g[u]=f[u];
                f[u]=f[v]+1;
            }
            else if(f[v]+1>g[u]) g[u]=f[v]+1;
        }
    };
    _dfs(1, 0);
    // for(int i=1;i<=n;i++) cerr<<f[i]<<" "<<g[i]<<endl;
    function<void(int, int)> dfs=[&](int u, int fa)
    {
        
    };
    ll ans=0;
    // for(int u=1; u<=n; u++)
    //     ans+=min(f[u]-1, g[u]+1);
    // cout<<ans<<endl;
    return 0;
}
