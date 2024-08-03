// Problem: 机器任务
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/378/
// Memory Limit: 10 MB
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
	int n, m, k;
	while(cin>>n, n)
	{
		cin>>m>>k;
		vector<vector<int>> g(n, vector<int>());
		for(int i=1, u, v, w; i<=k; i++)
		{
			cin>>w>>u>>v;
			if(!u || !v) continue;
			g[u].eb(v);
		}
		vector<bool> vis(m, 0);
		vector<int> match(m, 0);
		function<bool(int)> dfs=[&](int u)
		{
			each(v, g[u])
			{
				if(vis[v]) continue;
				vis[v]=1;
				if(!match[v] || dfs(match[v]))
				{
					match[v]=u;
					return 1;
				}
			}
			return 0;
		};
		int ans=0;
		for(int i=1; i<n; i++)
		{
			fill(all(vis), 0);
			ans+=dfs(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
