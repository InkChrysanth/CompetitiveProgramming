// Problem: 交通实时查询系统
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/400/
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

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	while(cin>>n>>m, n || m)
	{
		vector<vector<pii>> g(n+1, vector<pii>());
		for(int i=1, u, v; i<=m; i++)
		{
			cin>>u>>v;
			if(u==v) continue;
			g[u].eb(mp(v, i));
			g[v].eb(mp(u, i));
		}
		
		int root, dn=0;
		vector<vector<int>> dcc; dcc.eb();
		vector<bool> cut_point(n+1, 0);
		vector<int> dfn(n+1, 0), low(n+1, 0);
		stack<int> stk;
		function<void(int)> tarjan=[&](int u)
		{
			dfn[u]=low[u]=++dn;
			if(!g[u].size() && u==root) return void(dcc.eb(vector<int>{u}));
			stk.push(u);
			int cnt=0;
			each(t, g[u])
			{
				int v=t.fi;
				if(!dfn[v])
				{
					tarjan(v);
					cmin(low[u], low[v]);
					if(low[v]>=dfn[u])
					{
						cnt++;
						if(cnt>1 || u!=root) cut_point[u]=1;
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
				
		int dcc_cnt=dcc.size()-1, tot=dcc_cnt;
		vector<int> id(n+1);
		for(int i=1; i<=n; i++)
			if(cut_point[i])
				id[i]=++tot;
		
		vector<int> c(n+1), pos(m+1);
		vector<vector<int>> G(2*(n+1), vector<int>());
		for(int i=1; i<=dcc_cnt; i++)
		{
			each(x, dcc[i])
			{
				c[x]=i;
				if(cut_point[x])
				{
					G[i].eb(id[x]);
					G[id[x]].eb(i);
				}
				else id[x]=i;
			}
			each(u, dcc[i])
			{
				c[u]=0;
				each(t, g[u])
				{
					int v=t.fi, cur=t.se;
					if(c[v]==i) pos[cur]=i;
				}
			}
		}
		
		vector<vector<int>> fa(tot+1, vector<int>(21, 0));
		vector<int> dep(tot+1, 0), dist(tot+1, 0);
		function<void(int, int)> dfs=[&](int u, int pre)
		{
		    fa[u][0]=pre;
		    dep[u]=dep[pre]+1;
		    dist[u]=dist[pre]+(u>dcc_cnt);
		    for(int k=1; k<=20; k++)
		        fa[u][k]=fa[fa[u][k-1]][k-1];
		    for(auto v: G[u])
		    {
		        if(v==pre) continue;
		        dfs(v, u);
		    }
		};
		
		for(int i=1; i<=tot; i++)
			if(!dep[i])
				dfs(i, 0);
				
		auto lca=[&](int a, int b)
		{
		    if(dep[a]<dep[b]) swap(a, b);
		    for(int k=20; k>=0; k--)
		        if(dep[fa[a][k]]>=dep[b])
		            a=fa[a][k];
		    if(a==b) return b;
		    for(int k=20; k>=0; k--)
		    {
		        if(fa[a][k]!=fa[b][k])
		        {
		            a=fa[a][k];
		            b=fa[b][k];
		        }
		    }
		    return fa[a][0];
		};
		
		int q;
		cin>>q;
		for(int x, y; q>=1; q--)
		{
			cin>>x>>y;
			x=pos[x], y=pos[y];
			int _lca=lca(x, y);
			cout<<dist[x]+dist[y]-dist[_lca]-dist[fa[_lca][0]]<<endl;
		}
	}
	return 0;
}
