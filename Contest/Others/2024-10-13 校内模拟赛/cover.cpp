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

signed main()
{
	Fre("cover");
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	vector<int> ans(n+1);
	vector<vector<int>> g(n);
	for(int i=1; i<=n-1; i++)
	{
		int u, v; cin>>u>>v;
		u--, v--;// use 0-indexed
		g[u].eb(v); g[v].eb(u);
	}
	for(int i=0; i<(1<<n); i++)
	{
		vector<bool> st(n);
		for(int j=0; j<n; j++)
		{
			if((i>>j)&1)
			{
				st[j]=true;
				each(v, g[j])
					st[v]=true;
			}
		}
		int cnt=0;
		for(int j=0; j<n; j++)
			cnt+=st[j];
		ans[cnt]++;
	}
	for(int i=0; i<=n; i++)
		cout<<ans[i]<<endl;
	return 0;
}
