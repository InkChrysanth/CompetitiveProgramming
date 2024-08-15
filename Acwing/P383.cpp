#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	for(int n, m, st, ed; T>0; T--)
	{
		cin>>n>>m;
		vector<vector<pii>> adj(n+1);
		for(int i=1, u, v, w; i<=m; i++)
		{
			cin>>u>>v>>w;
			adj[u].eb(mp(v, w));
		}
		cin>>st>>ed;
		vector<array<int, 2>> dist(n+1, {inf, inf}), cnt(n+1, {0, 0});
		dist[st][0]=0; cnt[st][0]=1;
		vector<array<bool, 2>> vis(n+1, {0, 0});
		auto cmp=[&](const pii &x, const pii &y){ return dist[x.fi][x.se]>dist[y.fi][y.se]; };
		priority_queue<pii, vector<pii>, decltype(cmp)> heap(cmp);
		//fi <-> node		se <-> type
		heap.push({st, 0});
		while(heap.size())
		{
			int u=heap.top().fi, type=heap.top().se;
			heap.pop();
			if(vis[u][type]) continue;
			vis[u][type]=true;
			each(t, adj[u])
			{
				int v=t.fi, w=t.se;
				if(dist[v][0]>dist[u][type]+w)
				{
					dist[v][1]=dist[v][0], cnt[v][1]=cnt[v][0];
					dist[v][0]=dist[u][type]+w, cnt[v][0]=cnt[u][type];
					heap.push(mp(v, 0)); heap.push(mp(v, 1));
				}
				else if(dist[v][0]==dist[u][type]+w) cnt[v][0]+=cnt[u][type];
				else if(dist[v][1]>dist[u][type]+w)
				{
					dist[v][1]=dist[u][type]+w, cnt[v][1]=cnt[u][type];
					heap.push(mp(v, 1));
				}
				else if(dist[v][1]==dist[u][type]+w) cnt[v][1]+=cnt[u][type];
			}
		}
		int ans=cnt[ed][0];
		if(dist[ed][0]+1==dist[ed][1]) ans+=cnt[ed][1];
		cout<<ans<<endl;
	}
	return 0;
}
