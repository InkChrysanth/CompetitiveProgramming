// Problem: 捉迷藏
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/381/
// Memory Limit: 64 MB
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
constexpr int N=210;

bool g[N][N];
int match[N];
bool vis[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		g[u][v]=1;
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) for(int k=1; k<=n; k++)
		if(g[i][k] && g[k][j]) g[i][j]=1;
	function<bool(int)> dfs=[&](int u)
	{
		for(int v=1; v<=n; v++)
		{
			if(g[u][v] && !vis[v])
			{
				vis[v]=1;
				if(!match[v] || dfs(match[v]))
				{
					match[v]=u;
					return 1;
				}	
			}
		}
		return 0;
	};
	int ans=n;
	for(int i=1; i<=n; i++)
	{
		memset(vis, 0, sizeof vis);
		ans-=dfs(i);
	}
	cout<<ans<<endl;
	return 0;
}