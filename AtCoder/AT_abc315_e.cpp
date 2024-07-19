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
constexpr int N=200010;

vector<int> g[N];
bool vis[N];

void dfs(int u)
{
	vis[u]=1;
	each(v, g[u])
	{
		if(!vis[v])
			dfs(v);
	}
	if(u!=1) cout<<u<<' ';
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int m;
		cin>>m;
		for(int j=1; j<=m; j++)
		{
			int x;
			cin>>x;
			g[i].eb(x);
		}
	}
	dfs(1);
	return 0;
}
