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
	cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	vector<int> col(n+1);
    	for(int i=1; i<=n; i++)
    		cin>>col[i];
    	vector<vector<int>> adj(n+1);
    	for(int i=1, u, v; i<=n-1; i++)
    	{
    		cin>>u>>v;
    		adj[u].eb(v);
    		adj[v].eb(u);
		}
		ll ans=0;
		vector<int> cnt(n+1, 0);
		function<void(int, int)> dfs=[&](int u, int par)
		{
			int bk=cnt[col[u]];
			each(v, adj[u]) if(v!=par)
			{
				cnt[col[u]]=1;
				dfs(v, u);
			}
			ans+=(cnt[col[u]]=bk);
			cnt[col[u]]++;
		};
		dfs(1, 0);
		cout<<ans<<endl;
	}
	return 0;
}
