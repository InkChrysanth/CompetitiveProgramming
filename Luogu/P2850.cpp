// Problem: P2850 [USACO06DEC] Wormholes G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2850
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
constexpr int N=510;

vector<pii> g[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n, m, w;
		cin>>n>>m>>w;
		for(int i=1, a, b, c; i<=m; i++)
		{
			cin>>a>>b>>c;
			g[a].eb(mp(b, c));
			g[b].eb(mp(a, c));
		}
		for(int i=1, a, b, c; i<=w; i++)
		{
			cin>>a>>b>>c;
			g[a].eb(mp(b, -c));
		}
		vector<int> dist(n+1, 0), cnt(n+1, 0);
		vector<bool> vis(n+1, 0);
		queue<int> q;
		for(int i=1; i<=n; i++)
		{
			q.push(i);
			vis[i]=1;
		}
		bool flag=0;
		while(q.size())
		{
			int u=q.front();
			q.pop();
			vis[u]=0;
			each(t, g[u])
			{
				int v=t.fi, www=t.se;
				if(dist[v]>dist[u]+www)
				{
					dist[v]=dist[u]+www;
					cnt[v]=cnt[u]+1;
					if(cnt[v]>=n) 
					{
						flag=1;
						break;
					}
					if(!vis[v]) q.push(v), vis[v]=1;
				}
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
		for(int i=1; i<=n; i++) g[i].clear();
	}
	return 0;
}
