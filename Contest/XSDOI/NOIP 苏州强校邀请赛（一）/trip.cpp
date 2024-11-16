//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int K=21;

signed main()
{
	setIO("trip");
	int n, m, S, T; cin>>n>>m>>S>>T; S--, T--;
	vector<vector<pii>> g(n*K);
	for(int i=1; i<=m; i++)
	{
		int u, v, w; char ch;
		cin>>u>>v>>w>>ch;
		u--, v--;
		if(ch=='G')
			for(int k=0; k<K; k++)
				g[u+k*n].eb(mp(v+k*n, (w+(1<<k)-1)/(1<<k)));// ceil(x)
		else
			for(int k=0; k<K; k++)
				g[u+k*n].eb(mp(v, (w+(1<<k)-1)/(1<<k)));
	}
	int p; cin>>p;
	for(int i=1; i<=p; i++)
	{
		int u, w; cin>>u>>w; u--;
		for(int k=0; k<K-1; k++)
			g[u+k*n].eb(mp(u+(k+1)*n, w));
	}
	vector<int> dist(n*K, inf);
	vector<bool> vis(n*K);
	auto dijkstra=[&]()
	{
		priority_queue<pii, vector<pii>, greater<pii>> heap;
		dist[S]=0;
		heap.push(mp(0, S));
		while(heap.size())
		{
			int u=heap.top().se;
			heap.pop();
			if(vis[u]) continue;
			vis[u]=true;
			each(t, g[u])
			{
				int v=t.fi, w=t.se;
				if(!vis[v] && dist[v]>dist[u]+w) 
				{
					dist[v]=dist[u]+w;
					heap.push(mp(dist[v], v));
				}
			}
		}
	};
    dijkstra();
	int ans=inf;
	for(int k=0; k<K; k++)
		cmin(ans, dist[T+k*n]);
	cout<<(ans==inf ? -1 : ans)<<endl;
	return 0;
}
// graphs(dijkstra)