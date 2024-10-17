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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int mod=998244353;

struct Node{ int u, v, w; };
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	vector<Node> E(m+1);
	vector<vector<pii>> g(n+1);
	for(int i=1; i<=m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		E[i]={u, v, w};
		g[u].eb(mp(v, w));
		g[v].eb(mp(u, w));
	}
	vector<ll> dist1(n+1, llinf), dist2(n+1, llinf);
	vector<ll> cnt1(n+1), cnt2(n+1);
	auto dijkstra=[&](int s, vector<ll> &dist, vector<ll> &cnt)
	{
		vector<bool> vis(n+1);
		priority_queue<pll, vector<pll>, greater<pll>> heap;
		heap.em(mp(dist[s]=0, s)); cnt[s]=1;
		while(heap.size())
		{
			int u=heap.top().se;
			heap.pop();
			if(vis[u]) continue;
			vis[u]=true;
			each(t, g[u])
			{
				ll v=t.fi, w=t.se;
				if(dist[v]>dist[u]+w)
					dist[v]=dist[u]+w, cnt[v]=cnt[u], heap.em(mp(dist[v], v));
				else if(dist[v]==dist[u]+w)
					(cnt[v]+=cnt[u])%=mod;
			}
		}
	};
	dijkstra(1, dist1, cnt1);
	// for(int i=1; i<=n; i++) cerr<<dist1[i]<<" \n"[i==n];
	dijkstra(n, dist2, cnt2);
	// for(int i=1; i<=n; i++) cerr<<dist2[i]<<" \n"[i==n];
	for(int i=1; i<=m; i++)
	{
		bool flag=false;
		int u=E[i].u, v=E[i].v, w=E[i].w;
		if(dist1[u]+w+dist2[v]==dist1[n])
			flag|=(cnt1[u]*cnt2[v]==cnt1[n]);
		swap(u, v);
		if(dist1[u]+w+dist2[v]==dist1[n])
			flag|=(cnt1[u]*cnt2[v]==cnt1[n]);
		cout<<(flag ? "Yes" : "No")<<endl;
	}
	return 0;
}
// graphs(dijkstra)