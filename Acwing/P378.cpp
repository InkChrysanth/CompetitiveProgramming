// Problem: 骑士放置
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/380/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

int dx[]={0, -1, -1, 1, 1, -2, -2, 2, 2},
	dy[]={0, -2, 2, -2, 2, 1, -1, 1, -1};

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=111;

bool g[N][N], vis[N][N];
pii match[N][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1, x, y; i<=k; i++)
		cin>>x>>y, g[x][y]=1;
	auto check=[&](pii pt)
	{ return pt.fi>=1 && pt.fi<=n && pt.se>=1 && pt.se<=m && !g[pt.fi][pt.se] && !vis[pt.fi][pt.se]; };
	function<bool(pii)> dfs=[&](pii u)
	{
		for(int i=1; i<=8; i++)
		{
			pii v=mp(u.fi+dx[i], u.se+dy[i]);
			if(!check(v)) continue;
			vis[v.fi][v.se]=1;
			pii &_v=match[v.fi][v.se];
			if(!_v.fi || dfs(_v))
			{
				_v=u;
				return 1;
			}
		}
		return 0;
	};
	int ans=n*m-k;
	for(int i=n; i>=1; i--) for(int j=m; j>=1; j--)
	{
		memset(vis, 0, sizeof vis);
		if((i+j)&1 || g[i][j]) continue;
		ans-=dfs(mp(i, j));
	}
	cout<<ans<<endl;
	return 0;
}
