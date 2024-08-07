// Problem: P3384 【模板】重链剖分/树链剖分
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3384
// Memory Limit: 128 MB
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
#define Fo(s) freopen(s,"a",stdout)
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
constexpr int N=100010, M=N<<5;

struct Node
{
	int l, r;
	ll add, sum;
} tr[M];

int n, m, root, mod;
int a[N];
vector<int> g[N];
int id[N], rid[N], tot;
int sz[N], dep[N];
int fa[N], son[N], top[N];

void dfs(int u, int pre)
{
	dep[u]=dep[pre]+1;
	fa[u]=pre;
	sz[u]=1;
	each(v, g[u])
	{
		if(v==pre) continue;
		dfs(v, u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

void _dfs(int u, int pre)
{
	top[u]=pre;
	id[u]=++tot;
	rid[tot]=u;
	if(!son[u]) return;
	_dfs(son[u], pre);
	each(v, g[u])
	{
		// if(v==pre || v==son[u]) continue;
		if(!id[v]) _dfs(v, v);
	}
	
}

void pushup(int u){ tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%mod; }

void pushdown(int u)
{
	if(tr[u].add)
	{
		(tr[u<<1].sum+=tr[u].add*(tr[u<<1].r-tr[u<<1].l+1))%=mod;
		(tr[u<<1].add+=tr[u].add)%=mod;
		(tr[u<<1|1].sum+=tr[u].add*(tr[u<<1|1].r-tr[u<<1|1].l+1))%=mod;
		(tr[u<<1|1].add+=tr[u].add)%=mod;
		tr[u].add=0;
	}
}

void build(int u, int l, int r)
{
	tr[u].l=l, tr[u].r=r;
	if(l==r)
	{
		tr[u].sum=a[rid[l]];
		return;	
	}
	int mid=(l+r)>>1;
	build(u<<1, l, mid);
	build(u<<1|1, mid+1, r);
	pushup(u);
}

void modify(int u, int l, int r, int x)
{
	if(l<=tr[u].l && r>=tr[u].r)
	{
		tr[u].add+=x;
		tr[u].sum+=x*(tr[u].r-tr[u].l+1);
		return;
	}
	pushdown(u);
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l<=mid) modify(u<<1, l, r, x);
	if(r>mid) modify(u<<1|1, l, r, x);
	pushup(u);
}

int query(int u, int l, int r)
{
	if(l<=tr[u].l && r>=tr[u].r) return tr[u].sum;
	pushdown(u);
	int res=0;
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l<=mid) (res+=query(u<<1, l, r))%=mod;
	if(r>mid) (res+=query(u<<1|1, l, r))%=mod;
	return res;
}

void modify_path(int x, int y, int w)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x, y);
		modify(1, id[top[x]], id[x], w);	
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x, y);
	modify(1, id[x], id[y], w);
}

int query_path(int x, int y)
{
	int res=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x, y);
		(res+=query(1, id[top[x]], id[x]))%=mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x, y);
	(res+=query(1, id[x], id[y]))%=mod;
	return res;
}

void modify_subtree(int u, int w){ modify(1, id[u], id[u]+sz[u]-1, w); }

int query_subtree(int u)
{
	int res=0;
	(res+=query(1, id[u], id[u]+sz[u]-1))%=mod;
	return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>root>>mod;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1, u, v; i<=n-1; i++)
	{
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	
	dfs(root, 0);
	_dfs(root, root);
	build(1, 1, n);
	
	for(int i=1, opt, x, y, z; i<=m; i++)
	{
		cin>>opt;
		switch(opt)
		{
			case 1:
				cin>>x>>y>>z;
				z%=mod;
				modify_path(x, y, z);
				break;
			case 2:
				cin>>x>>y;
				cout<<query_path(x, y)<<endl;
				break;
			case 3:
				cin>>x>>z;
				modify_subtree(x, z);
				break;
			case 4:
				cin>>x;
				cout<<query_subtree(x)<<endl;
				break;
			default: break;
		}
	}
	return 0;
}
