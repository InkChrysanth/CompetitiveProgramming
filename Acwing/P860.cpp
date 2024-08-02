// Problem: 染色法判定二分图
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/862/
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	vector<vector<int>> g(n+1, vector<int>());
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	vector<int> color(n+1, 0);
	function<bool(int, int)> dfs=[&](int u, int c)
	{
		color[u]=c;
		each(v, g[u])
		{
			if(!color[v] && !dfs(v, 3-c)) return false;
			else if(color[v]==c) return false;
		}
		return true;
	};
	bool flag=0;
	for(int i=1; i<=n; i++)
		if(!color[i] && !dfs(i, 1))
		{
			flag=1;
			break;
		}
	cout<<(flag?"No":"Yes")<<endl;
	return 0;
}
