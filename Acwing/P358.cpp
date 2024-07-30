// Problem: 岛屿
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/360/
// Memory Limit: 256 MB
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
constexpr int N=1000010;

int n;
int deg[N], tar[N], w[N];
int que[N], hh, tt;
ll f[N], g[N];// g: diameter f: chain

ll calc_cycle(int u)
{
	int _u=u;
	ll m1=f[u], m2=f[u];
	//res1: 1 -> 2
	//res2: 1 -> 3 -> 2
	ll res1=g[u], res2=-inf;
	ll pre=w[u];
	u=tar[u];
	while(u!=_u)
	{
		deg[u]=0;
		cmax(res1, f[u]+pre+m1);
		cmax(res2, f[u]-pre+m2);
		cmax(res1, g[u]);
		cmax(m1, f[u]-pre);
		cmax(m2, f[u]+pre);
		pre+=w[u];
		u=tar[u];
	}
	return max(res1, res2+pre);
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>tar[i]>>w[i];
		deg[tar[i]]++;
	}
	hh=1, tt=0;
	for(int i=1; i<=n; i++)
		if(!deg[i])//from leaf nodes
			que[++tt]=i;
	while(hh<=tt)
	{
		int u=que[hh++];
		g[tar[u]]=max({g[tar[u]], f[tar[u]]+f[u]+w[u], g[u]});
		f[tar[u]]=max(f[tar[u]], f[u]+w[u]);
		if(!(--deg[tar[u]])) que[++tt]=tar[u];
	}
	ll ans=0;
	for(int i=1; i<=n; i++)
		if(deg[i])//from the nodes in the cycle
			ans+=calc_cycle(i);
	cout<<ans<<endl;
	return 0;
}
