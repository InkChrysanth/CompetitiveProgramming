// Problem: P1600 [NOIP2016 提高组] 天天爱跑步
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1600
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
constexpr int N=600010, K=21;

int n, m, ans[N];
vector<int> g[N];
vector<int> ap1[N], dap1[N], ap2[N], dap2[N];
int dep[N], w[N], cnt1[N], cnt2[N];
int fa[N][K];

void dfs(int u, int pre)
{
    fa[u][0]=pre;
    dep[u]=dep[pre]+1;
    for(int k=1; k<=20; k++)
        fa[u][k]=fa[fa[u][k-1]][k-1];
    for(auto v: g[u])
    {
        if(v==pre) continue;
        dfs(v, u);
    }
}

int lca(int a, int b)
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
}

void _dfs(int u, int pre)
{
	int _cnt1=cnt1[w[u]+dep[u]], _cnt2=cnt2[w[u]-dep[u]+N];
	each(t, ap1[u]) cnt1[t]++;
	each(t, ap2[u]) cnt2[t+N]++;
	each(t, dap1[u]) cnt1[t]--;
	each(t, dap2[u]) cnt2[t+N]--;
	each(v, g[u])
	{
		if(v==pre) continue;
		_dfs(v, u);
	}
	ans[u]=cnt1[w[u]+dep[u]]-_cnt1+cnt2[w[u]-dep[u]+N]-_cnt2;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v; i<=n-1; i++)
	{
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	for(int i=1; i<=n; i++) cin>>w[i];
	dfs(1, 0);
	for(int i=1, st, ed; i<=m; i++)
	{
		cin>>st>>ed;
		int _lca=lca(st, ed);
		// debug(_lca);
		ap1[st].eb(dep[st]);
		ap2[ed].eb(dep[st]-2*dep[_lca]);
		dap1[fa[_lca][0]].eb(dep[st]);
		dap2[_lca].eb(dep[st]-2*dep[_lca]);
	}
	_dfs(1, 0);
	for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
	return 0;
}
