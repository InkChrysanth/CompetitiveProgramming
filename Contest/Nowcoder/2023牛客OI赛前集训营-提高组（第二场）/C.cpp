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
	int n, m;
	cin>>n>>m;
	vector<ll> val(n+1);
	for(int i=1; i<=n; i++)
		cin>>val[i];
	vector<vector<int>> g(n+1);
	for(int i=1; i<=n; i++)
	{
		int k, x; cin>>k;
		for(int j=1; j<=k; j++)
			cin>>x, g[i].eb(x);
	}
	vector<int> id(n+1); int tot=0;
	vector<vector<bool>> con(m*2+1, vector<bool>(m*2+1));
	for(int i=1; i<=m; i++)
	{
		int u, v; cin>>u>>v;
		if(!id[u]) id[u]=++tot;
		if(!id[v]) id[v]=++tot;
		// assert(id[u]<=m && id[v]<=m);
		con[id[u]][id[v]]=con[id[v]][id[u]]=true;
	}
	ll ans=-llinf;
	vector<vector<ll>> f(n+1, vector<ll>(tot+1, -llinf));
	function<void(int)> dfs=[&](int u)
	{
		f[u][id[u]]=val[u];
		each(v, g[u])
		{
			dfs(v);
			ll mx=-llinf;
			for(int i=0; i<=tot; i++) if(!con[i][id[v]])
				cmax(mx, f[u][i]);
			// debug(u); debug(mx);
			for(int i=0; i<=tot; i++)
				cmax(f[u][i], f[v][i]+mx);
		}
		for(int i=0; i<=tot; i++) cmax(ans, f[u][i]);
	}; dfs(1);
	cout<<ans<<endl;
	return 0;
}
// dp, graphs