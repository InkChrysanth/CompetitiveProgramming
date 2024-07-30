// Problem: 观光奶牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/363/
// Memory Limit: 64 MB
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
constexpr int N=1010;
constexpr double eps=1e-4;

vector<pii> g[N];

signed main()
{
	cout<<fixed<<setprecision(2);
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1, u, v, w; i<=m; i++)
	{
		cin>>u>>v>>w;
		g[u].eb(mp(v, w));
	}
	auto check=[&](double mid) -> bool
	{
		vector<double> dist(n+1, 0);
		vector<int> cnt(n+1, 0);
		vector<bool> ins(n+1, 0);
		queue<int> q;
		for(int i=1; i<=n; i++)
			q.push(i), ins[i]=1;
		while(q.size())
		{
			int u=q.front();
			q.pop();
			ins[u]=false;
			each(t, g[u])
			{
				int v=t.fi;
				//sigma fi/sigma ti >= mid
				//sigma (ti * mid - fi) <= 0
				double w=t.se*mid-a[u];
				if(dist[v]>dist[u]+w)
				{
					dist[v]=dist[u]+w;
					cnt[v]=cnt[u]+1;
					if(cnt[v]>=n) return 1;
					if(!ins[v]) q.push(v), ins[v]=1;
				}
			}
		}
		return 0;
	};
	double l=0, r=1000, ans=r;
	while(l<=r)
	{
		double mid=(l+r)/2;
		if(check(mid)) l=mid+eps, ans=mid;
		else r=mid-eps;
	}
	cout<<ans<<endl;
	return 0;
}
