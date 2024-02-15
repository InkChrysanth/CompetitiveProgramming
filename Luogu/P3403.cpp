// Problem: P3403 跳楼机
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3403
// Memory Limit: 125 MB
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

const int N=100010;
const ll inf=LLONG_MAX;
ll h, ans, dist[N];
ll x, y, z;
vector<pll> g[N]; 
bool vis[N];

void dijkstra()
{
	fill(dist, dist+x, inf);
	fill(vis, vis+x, false);
	priority_queue<pll, vector<pll>, greater<pll>> heap;
	dist[1]=1ll; heap.push(mp(1ll, 1ll));
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
	h=ll_rd, x=ll_rd, y=ll_rd, z=ll_rd;
	if(x==1 || y==1 || z==1){cout<<h<<endl; return 0;}
	for(int i=0; i<x; i++)
	{
		g[i].emplace_back(mp((i+y)%x, y));
		g[i].emplace_back(mp((i+z)%x, z));
	}
	dijkstra();
	for(int i=0; i<x; i++) if(dist[i]<=h) ans+=(h-dist[i])/x+1;
	cout<<ans<<endl;
	return 0;
}