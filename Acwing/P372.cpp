// Problem: 棋盘覆盖
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/374/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

int dx[]={0, 1, -1, 0, 0}, dy[]={0, 0, 0, 1, -1};

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=101;

int n, m;
bool vis[N][N], g[N][N];
pii match[N][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, x, y; i<=m; i++)
	{
		cin>>x>>y;
		g[x][y]=1;
	}
	auto check=[&](pii pt){ return pt.fi>=1 && pt.fi<=n && pt.se>=1 && pt.se<=n && !g[pt.fi][pt.se] && !vis[pt.fi][pt.se]; };
	function<bool(pii)> dfs=[&](pii pt)
	{
		for(int i=1; i<=4; i++)
		{
			int x=pt.fi+dx[i], y=pt.se+dy[i];
			if(!check(mp(x, y))) continue;
			vis[x][y]=1;
			pii &t=match[x][y];
			if(!t.fi || dfs(t))
			{
				t=pt;
				return 1;
			}
		}
		return 0;
	};
	int ans=0;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
	{
		if((i+j)&1 || g[i][j]) continue;
		memset(vis, 0, sizeof vis);
		ans+=dfs(mp(i, j));
	}
	cout<<ans<<endl;
	return 0;
}