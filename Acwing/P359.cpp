// Problem: 创世纪
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/361/
// Memory Limit: 128 MB
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
constexpr int N=1000010;

vector<int> g[N];

int n, root;
int fa[N], f[N][2];
bool vis[N], flag;

void dp(int u)
{
	f[u][0]=f[u][1]=0;
	vis[u]=1;
	int del=inf;
	each(v, g[u])
	{
		if(v==root) continue;
		dp(v);
		int add=max(f[v][0], f[v][1]);
		f[u][0]+=add;
		cmin(del, add-f[v][0]);
	}
	f[u][1]=f[u][0]+1-del;
	if(fa[root]==u && flag) f[u][1]=f[u][0]+1;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1, x; i<=n; i++)
	{
		cin>>fa[i];
		g[fa[i]].eb(i);
	}
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) continue;
		root=i;
		while(!vis[fa[root]]) vis[root]=1, root=fa[root];
		
		flag=0;
		dp(root);
		int res=max(f[root][0], f[root][1]);
		
		flag=1;
		dp(root);
		res=max(res, f[root][0]);
		ans+=res;
	}
	cout<<ans<<endl;
	return 0;
}
