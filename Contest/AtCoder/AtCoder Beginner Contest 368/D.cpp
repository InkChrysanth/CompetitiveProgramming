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
    int n, k;
    cin>>n>>k;
    vector<vector<int>> g(n+1);
    for(int i=1, u, v; i<=n-1; i++)
    {
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    vector<int> sz(n+1, 0), a(n+1);
    for(int i=1; i<=k; i++)
    {
        cin>>a[i];
        sz[a[i]]=1;
    }
    function<void(int, int)> dfs=[&](int u, int par)
    {
        each(v, g[u])
        {
            if(v==par) continue;
            dfs(v, u);
            sz[u]+=sz[v];
        }
    };
    dfs(a[1], 0);
    int ans=0;
    for(int i=1; i<=n; i++)
        ans+=(sz[i]>0);
    cout<<ans<<endl;
	return 0;
}