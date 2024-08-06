// Problem: P3806 【模板】点分治 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3806
// Memory Limit: 500 MB
// Time Limit: 200000 ms
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
constexpr int N=10010, M=110;

int n, m, tot, root;
int q[M];
bool ans[M], vis[N];
vector<pii> g[N];
int mx[N], sz[N], cnt;
pii dist[N];

void get_root(int u, int fa)
{
	sz[u]=1, mx[u]=0;
	each(t, g[u])
	{
		int &v=t.fi;
		if(vis[v] || v==fa) continue;
		get_root(v, u);
		cmax(mx[u], sz[v]);
		sz[u]+=sz[v];
	}
	cmax(mx[u], cnt-sz[u]);
	if(mx[u]<mx[root]) root=u;
}
void get_dist(int u, int fa, int id, int d)
{
	dist[++tot]=mp(d, id);
	each(t, g[u])
	{
		int &v=t.fi, &w=t.se;
		if(vis[v] || v==fa) continue;
		get_dist(v, u, id, w+d);
	}
}

void calc(int u)
{
	tot=0; dist[++tot]=mp(0, u);
	each(t, g[u])
	{
		int &v=t.fi, &w=t.se;
		if(vis[v]) continue;
		get_dist(v, u, v, w);
	}
	sort(dist+1, dist+tot+1);
	for(int i=1; i<=m; i++)
	{
		if(ans[i]) continue;
		int l=1, r=tot;
		while(l<r)
		{
			if(dist[l].fi+dist[r].fi>q[i]) r--;
			else if(dist[l].fi+dist[r].fi<q[i]) l++;
			else if(dist[l].se==dist[r].se) r--;
			else
			{
				ans[i]=1;
				break;	
			}
		}
	}
}

void dfs(int u)
{
	vis[u]=1;
	calc(u);
	each(t, g[u])
	{
		int &v=t.fi;
		if(vis[v]) continue;
		cnt=sz[v];
		root=0;
		get_root(v, u);
		dfs(root);
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v, w; i<=n-1; i++)
	{
		cin>>u>>v>>w;
		g[u].eb(mp(v, w));
		g[v].eb(mp(u, w));
	}
	for(int i=1; i<=m; i++) cin>>q[i];
	root=0, mx[root]=cnt=n;
	get_root(1, 0);
	dfs(root);
	for(int i=1; i<=m; i++)
		cout<<(ans[i] ? "AYE" : "NAY")<<endl;
	return 0;
}
