//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
    	int n, m;
    	cin>>n>>m;
    	vector<vector<ld>> g(n+1, vector<ld>(n+1, 0));
		for(int i=1; i<=n; i++)
		{
			g[i][1]=1.0/i;
			for(int j=2; i>2 && j<=i; j++)
				g[i][j]=g[i-2][j-2]*(j-2)/i+g[i-2][j-1]*(i-j)/i;
		}
		vector<vector<int>> adj(n+1);
		for(int i=1; i<=m; i++)
    	{
    		int u, v;
    		cin>>u>>v;
    		adj[u].eb(v);
		}
		vector<ld> f(n+1, 0);
		f[n]=1;
		for(int i=n-1; i>=1; i--)
		{
			int deg=adj[i].size();
			vector<ld> val;
			each(p, adj[i]) val.eb(f[p]);
			sort(all(val), greater<ld>());
			for(int j=1; j<=deg; j++)
				f[i]+=g[deg][j]*val[j-1];
		}
		cout<<setprecision(20)<<f[1]<<endl;
	}
	return 0;
}
