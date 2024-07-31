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
constexpr int N=500010;

vector<pii> g[N];

int n, m;
int dfn[N], low[N], dn;
int stk[N], top;
vector<vector<int>> dcc;

void tarjan(int u, int pre)
{
	dfn[u]=low[u]=++dn;
	stk[++top]=u;
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
			t=stk[top--];
			dcc.back().eb(t);
		}while(t!=u);
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		g[u].eb(mp(v, i));
		g[v].eb(mp(u, i));
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i])
			tarjan(i, 0);
	cout<<dcc.size()<<endl;
	each(v, dcc)
	{
		cout<<v.size()<<' ';
		each(x, v) cout<<x<<' ';
		cout<<endl;
	}
	return 0;
}
