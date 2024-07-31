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
constexpr int N=200010;

vector<int> g[N];

int n, m;
int dfn[N], low[N], dn, root;
bool flag=0;

void tarjan(int u)
{
	dfn[u]=low[u]=++dn;
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
				if(u!=root || cnt>1)
				{
					flag=1;
					cout<<"Find Cut Point: "<<u<<endl;
				}
			}
		}
		else cmin(low[u], dfn[v]);
	}
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	for(root=1; root<=n; root++)
		if(!dfn[root])
			tarjan(root);
	cout<<(flag?"Exist":"Not Exist")<<endl;
	return 0;
}
