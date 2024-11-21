//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,t) (i)=min((i),(t))
#define cmax(i,t) (i)=max((i),(t))
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
constexpr int mod=1e9+7;

signed main()
{
	setIO();
    int n, m, S, T;
    cin>>n>>m>>S>>T;
    vector<vector<pii>> g(n+1);
	for(int i=1; i<=m; i++)
	{
		int u, v, w; cin>>u>>v>>w;
		g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
	}
    vector<ll> dist1(n+1, llinf), dist2(n+1, llinf);
	vector<ll> cnt1(n+1), cnt2(n+1);
	auto dijkstra=[&](int s, vector<ll> &dist, vector<ll> &cnt)
	{
		vector<bool> vis(n+1);
		priority_queue<pll, vector<pll>, greater<pll>> heap;
		heap.push(mp(dist[s]=0, s)); cnt[s]=1;
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
					dist[v]=dist[u]+w, cnt[v]=cnt[u], heap.push(mp(dist[v], v));
				else if(dist[v]==dist[u]+w)
					(cnt[v]+=cnt[u])%=mod;
			}
		}
	};
	dijkstra(S, dist1, cnt1);
	dijkstra(T, dist2, cnt2);
	ll ans=cnt1[T]*cnt2[S]%mod;
    for(int i=1; i<=n; i++)
		if(dist1[i]+dist2[i]==dist1[T] && dist1[i]==dist2[i])
            ans=(ans-cnt1[i]*cnt1[i]%mod*cnt2[i]%mod*cnt2[i]%mod+mod)%mod;
	for(int i=1; i<=n; i++)
        each(t, g[i])
			if(dist1[i]+dist2[t.fi]+t.se==dist1[T] && dist1[i]+t.se>dist2[t.fi] && dist2[t.fi]+t.se>dist1[i])
                ans=(ans-cnt1[i]*cnt1[i]%mod*cnt2[t.fi]%mod*cnt2[t.fi]%mod+mod)%mod;
    cout<<ans<<endl;
	return 0;
}
// graphs(dijkstra)