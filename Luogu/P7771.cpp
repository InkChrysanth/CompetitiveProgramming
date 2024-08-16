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
constexpr int N=100010, M=200010;

int n, m, st=1;
int deg[N], h[N];
vector<int> g[N];
int stk[M], top=0;

void dfs(int u)
{
	for(int &i=h[u]; i<g[u].size(); ) dfs(g[u][i++]);
	stk[++top]=u;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++)
	{
		cin>>u>>v;
		g[u].eb(v);
		deg[v]++;
	}
	bool flag=false, _flag=false;
	for(int i=1; i<=n; i++)
	{
		sort(all(g[i]));
		if(abs((int)g[i].size()-deg[i])>1) return cout<<"No"<<endl, 0;
		if(g[i].size()-deg[i]==1) flag=true, st=i;
		if(deg[i]-g[i].size()==1) _flag=true;
	}
	if(!(flag==_flag)) return cout<<"No"<<endl, 0;
	dfs(st);
	for(int i=top; i>=1; i--) cout<<stk[i]<<" ";
	return 0;
}
