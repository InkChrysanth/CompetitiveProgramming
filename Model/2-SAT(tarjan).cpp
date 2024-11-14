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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=2000010;

int n, m;
int low[N], dfn[N], dn, color[N];
int stk[N], top, cnt;
bool ins[N];
vector<int> g[N];

void tarjan(int u)
{
	low[u]=dfn[u]=++dn;
	stk[++top]=u, ins[u]=1;
	each(v, g[u])
	{
		if(!dfn[v]) tarjan(v), cmin(low[u], low[v]);
		else if(ins[v]) cmin(low[u], dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		do
		{
			u=stk[top--];
			color[u]=cnt;
			ins[u]=false;
		}while(dfn[u]!=low[u]);
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, a, va, b, vb; i<=m; i++)
	{
		cin>>a>>va>>b>>vb;
		g[a+n*(va&1)].eb(b+n*(vb^1));
		g[b+n*(vb&1)].eb(a+n*(va^1));
		//Rules: 记 x+n 为 ¬x
		//a 1  b 0: -a -> -b, b -> a 
		//a 1  b 1: -a -> b, -b -> a
		//a 0  b 0: a -> -b, b -> -a
		//a 0  b 1: a -> b, -b -> -a
	}
	for(int i=1; i<=2*n; i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1; i<=n; i++)
		if(color[i]==color[i+n])
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	//x 所在的强连通分量的拓扑序在 ¬x 所在的强连通分量的拓扑序之后取 x 为真
	//tarjan求得的为逆拓扑序
	cout<<"POSSIBLE"<<endl;
	for(int i=1; i<=n; i++)
		cout<<(color[i]<color[i+n])<<' ';
	return 0;
}