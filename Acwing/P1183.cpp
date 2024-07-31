// Problem: 电力
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1185/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
constexpr int N=10010;

vector<int> g[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	while(cin>>n>>m, n || m)
	{
		for(int i=1, u, v; i<=m; i++)
		{
			cin>>u>>v;
			g[u].eb(v);
			g[v].eb(u);
		}
		int dn=0, root, ans=0;
		vector<int> dfn(n), low(n);
		function<void(int)> tarjan=[&](int u)
		{
			dfn[u]=low[u]=++dn;
			int cnt=0;
			each(v, g[u])
			{
				if(!dfn[v])
				{
					tarjan(v);
					cmin(low[u], low[v]);
					if(low[v]>=dfn[u]) cnt++;
				}
				else cmin(low[u], dfn[v]);
			}
			if(u!=root) cnt++;
			cmax(ans, cnt);
		};
		int cnt=0;
		for(root=0; root<n; root++)
			if(!dfn[root])
				cnt++, tarjan(root);
		cout<<ans+cnt-1<<endl;
		for(int i=0; i<n; i++) g[i].clear();
	}
	return 0;
}
