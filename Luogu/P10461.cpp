// Problem: P10461 Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10461
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	while(cin>>n>>k, n || k)
	{
		vector<vector<pii>> g(n+1, vector<pii>());
		vector<bool> vis(n+1, 0);
		for(int i=1, u, v, w; i<=n-1; i++)
		{
			cin>>u>>v>>w;
			g[u+1].eb(mp(v+1, w));
			g[v+1].eb(mp(u+1, w));
		}
		vector<int> dist;
		function<void(int, int, int)> get_dist=[&](int u, int fa, int d)
		{
			dist.eb(d);
			each(t, g[u])
			{
				int &v=t.fi, &w=t.se;
				if(v==fa || vis[v]) continue;
				get_dist(v, u, d+w);
			}
		};
		
		auto calc=[&](int u, int d)
		{
			dist.clear();
			get_dist(u, 0, d);
			sort(all(dist));
			int res=0;
			for(int l=0, r=dist.size()-1; l<r; )
			{
				if(dist[r]+dist[l]<=k) res+=r-l, l++;	
				else r--;
			}
			// debug(res);
			return res;
		};
		
		int ans=0, root=0, cnt=n;
		vector<int> mx(n+1), sz(n+1);
		mx[root]=n;
		
		function<void(int, int)> get_root=[&](int u, int fa)
		{
			mx[u]=0, sz[u]=1;
			each(t, g[u])
			{
				int &v=t.fi, &w=t.se;
				if(v==fa || vis[v]) continue;
				get_root(v, u);
				sz[u]+=sz[v];
				cmax(mx[u], sz[v]);
			}
			cmax(mx[u], cnt-sz[u]);
			if(mx[u]<mx[root]) root=u;
		};
		
		function<void(int)> dfs=[&](int u)
		{
			vis[u]=1;
			ans+=calc(u, 0);
			each(t, g[u])
			{
				int &v=t.fi, &w=t.se;
				if(vis[v]) continue;
				ans-=calc(v, w);
				cnt=sz[v];
				root=0;
				get_root(v, u);
				dfs(root);
			}
		};
		
		get_root(1, 0);
		dfs(root);
		cout<<ans<<endl;
	}
	return 0;
}
