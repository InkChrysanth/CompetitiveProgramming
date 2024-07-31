// Problem: 矿场搭建
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/398/
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
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=1010;

vector<int> g[N];
vector<vector<int>> dcc;
vector<int> deg(N, 0);

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int m, n, dn, tot=0, root;
	while(cin>>m, m)
	{
		cout<<"Case "<<++tot<<": ";
		n=0, dn=0;
		for(int i=1, u, v; i<=m; i++)
		{
			cin>>u>>v;
			n=max({n, u, v});
			g[u].eb(v); deg[u]++;
			g[v].eb(u); deg[v]++;
		}
		vector<int> dfn(n+1, 0), low(n+1, 0);
		vector<bool> cut_point(n+1, 0);
		stack<int> stk;
		function<void(int)> tarjan=[&](int u)
		{
			dfn[u]=low[u]=++dn;
			stk.push(u);
			if(u==root && !deg[u]){ dcc.eb(vector<int>{u}); return; }
			int cnt=0;
			each(v, g[u])
			{
				if(!dfn[v])
				{
					tarjan(v);
					cmin(low[u], low[v]);
					if(low[v]>=dfn[u])
					{
						cnt++;
						if(u!=root || cnt>1) cut_point[u]=1;
						dcc.eb();
						int t;
						do
						{
							t=stk.top(); stk.pop();
							dcc.back().eb(t);
						}while(t!=v);
						dcc.back().eb(u);
					}
				}
				else cmin(low[u], dfn[v]);
			}
		};
		for(root=1; root<=n; root++)
			if(!dfn[root])
				tarjan(root);
		int res=0;
		ull ans=1;
		// for(int i=1; i<=n; i++) debug(cut_point[i]);
		each(v, dcc)
		{
			int cnt=0;
			each(x, v) if(cut_point[x]) cnt++;
			if(!cnt)
			{
				if(v.size()>1) res+=2, ans*=(v.size()*(v.size()-1)/2);
				else res++;
			}
			else if(cnt==1) res++, ans*=(v.size()-1);
		}
		cout<<res<<' '<<ans<<endl;
		for(int i=1; i<=n; i++) g[i].clear();
		dcc.clear(); deg.clear();
	}
	return 0;
}