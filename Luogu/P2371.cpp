// Problem: P2371 [国家集训队] 墨墨的等式
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2371
// Memory Limit: 512 MB
// Time Limit: 1000 ms

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=500010;
const ll inf=LLONG_MAX;
ll n, l, r, m, ans, dist[N];
vector<pll> g[N];
vector<ll> a;
bool vis[N];

void dijkstra()
{
	fill(dist, dist+m, inf);
	fill(vis, vis+m, false);
	priority_queue<pll, vector<pll>, greater<pll>> heap;
	dist[0]=0ll; heap.push(mp(0ll, 0ll));
	while(heap.size())
	{
		auto u=heap.top().second; heap.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto [v, w]: g[u])
			if(dist[v]>dist[u]+w)
				dist[v]=dist[u]+w, heap.push(mp(dist[v], v));
	}
}


signed main()
{
	cin.tie(0); cout.tie(0);
	n=ll_rd, l=ll_rd, r=ll_rd;
	for(int i=1; i<=n; i++)
	{
		ll x=ll_rd;
		if(x) a.emplace_back(x);
	}
	if(!a.size()){cout<<0<<endl; return 0;}
	sort(a.begin(), a.end()); m=a[0];
	for(int i=0; i<=m-1; i++)
		for(int j=1; j<a.size(); j++)
			g[i].emplace_back(mp((i+a[j])%m, a[j]));
	dijkstra();
	for(int i=0; i<=m-1; i++)
	{
		if(dist[i]<=r) ans+=(r-dist[i])/m+1ll;
		if(dist[i]<=l-1) ans-=(l-1-dist[i])/m+1ll;
	}
	cout<<ans<<endl;
	return 0;
}