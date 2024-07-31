// Problem: 网络
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/366/
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
constexpr int N=100010;

vector<pii> g[N];
vector<int> G[N];


signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m, tc=0;
	while(cin>>n>>m, n || m)
	{
		vector<vector<int>> dcc;
		cout<<"Case "<<++tc<<":"<<endl;
		
		for(int i=1, u, v; i<=m; i++)
		{
			cin>>u>>v;
			g[u].eb(mp(v, i));
			g[v].eb(mp(u, i));
		}
		
		int dn=0;
		stack<int> stk;
		vector<int> dfn(n+1, 0), low(n+1, 0);
		function<void(int, int)> tarjan=[&](int u, int pre)
		{
			dfn[u]=low[u]=++dn;
			stk.push(u);
			each(t, g[u])
			{
				int cur=t.se, v=t.fi;
				if(cur==pre) continue;
				if(!dfn[v])
				{
					tarjan(v, cur);
					cmin(low[u], low[v]);
				}
				else cmin(low[u], dfn[v]);
			}
			if(low[u]==dfn[u])
			{
				dcc.eb();
				int t;
				do
				{
					t=stk.top(); stk.pop();
					dcc.back().eb(t);
				}while(t!=u);
			}
		};
		
		for(int i=1; i<=n; i++)
			if(!dfn[i])
				tarjan(i, 0);
		
		int tot=0;
		vector<int> id(n+1, 0);
		each(v, dcc)
		{
			tot++;
			each(x, v) id[x]=tot;
		}
		for(int u=1; u<=n; u++)
		{
			each(t, g[u])
			{
				int v=t.fi;
				if(id[u]==id[v]) continue;
				G[id[u]].eb(id[v]);
			}
		}
		vector<vector<int>> fa(tot+1, vector<int>(21, 0));
		vector<int> dep(tot+1, 0);
		function<void(int, int)> dfs=[&](int u, int pre)
		{
		    fa[u][0]=pre;
		    dep[u]=dep[pre]+1;
		    for(int k=1; k<=20; k++)
		        fa[u][k]=fa[fa[u][k-1]][k-1];
		    for(auto v: G[u])
		    {
		        if(v==pre) continue;
		        dfs(v, u);
		    }
		};
		
		dfs(1, 0);
		
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
		
		vector<int> p(tot+1);
		for(int i=1; i<=tot; i++) p[i]=i;
		function<int(int)> find=[&](int x)
		{ return x==p[x] ? x : p[x]=find(p[x]); };
		
		int q;
		cin>>q;
		int ans=dcc.size()-1;
		for(int u, v; q>=1; q--)
		{
			cin>>u>>v;
			u=find(id[u]), v=find(id[v]);
			int _lca=lca(u, v);
			while(dep[u]>dep[_lca])
			{
				p[u]=fa[u][0];
				ans--;
				u=find(u);
			}
			while(dep[v]>dep[_lca])
			{
				p[v]=fa[v][0];
				ans--;
				v=find(v);
			}
			cout<<ans<<endl;
		}
		cout<<endl;
		for(int i=1; i<=n; i++) g[i].clear();
		for(int i=1; i<=tot; i++) G[i].clear();
	}
	return 0;
}
