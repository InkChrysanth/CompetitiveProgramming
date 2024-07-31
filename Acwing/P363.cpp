// Problem: B城
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/365/
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

vector<int> g[N];

int n, m;
int dfn[N], low[N], sz[N], dn;
ll ans[N];
bool cut_point[N];

void tarjan(int u)
{
	dfn[u]=low[u]=++dn;
	sz[u]=1;
	int cnt=0, sum=0;
	each(v, g[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			sz[u]+=sz[v];
			cmin(low[u], low[v]);
			if(low[v]>=dfn[u])
			{
				cnt++;
				sum+=sz[v];
				ans[u]+=1ll*(n-sz[v])*sz[v];
				if(u!=1 || cnt>1) cut_point[u]=1;
			}
		}
		else cmin(low[u], dfn[v]);
	}
	if(cut_point[u]) ans[u]+=1ll*(n-(sum+1))*(sum+1)+(n-1);
	else ans[u]=2*(n-1);
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		if(u==v) continue;
		g[u].eb(v);
		g[v].eb(u);
	}
	tarjan(1);
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<endl;
	return 0;
}
