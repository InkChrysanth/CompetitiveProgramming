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

signed main()
{
	setIO();
	int n, m; cin>>n>>m;
	vector<vector<int>> g(n, vector<int>(n, inf));
	for(int i=1; i<=m; i++)
	{
		int u, v, w; cin>>u>>v>>w;
		u--, v--;// use 0-indexed
        if(u==v) continue;
		g[u][v]=g[v][u]=min(g[u][v], w);
	}
    ll ans=llinf;
    vector<bool> vis(n);
    vector<vector<int>> layer(n);
	function<void(int, int, int, ll)> dfs=[&](int k, int id, int cnt, ll res)
	{
		if(res>=ans) return;
        if(layer[k-1].empty()) return;
        if(cnt==n)
        {
            cmin(ans, res);
            return;
        }
        if(id==n)
        {
            dfs(k+1, 0, cnt, res);
            return;
        }
        if(vis[id])
        {
            dfs(k, id+1, cnt, res);
            return;
        }
        vis[id]=true;
        int mn=inf;
        each(par, layer[k-1]) if(par!=id)
            cmin(mn, g[par][id]);
        layer[k].eb(id);
        dfs(k, id+1, cnt+1, res+(ll)mn*k);
        layer[k].pop_back();
        vis[id]=false;
        dfs(k, id+1, cnt, res);
	};
	for(int i=0; i<n; i++)
	{
		vis[i]=1;
        layer[0].eb(i);
		dfs(1, 0, 1, 0);
		vis[i]=0;
        for(int k=0; k<n; k++) layer[k].clear();
	}
	cout<<ans<<endl;
	return 0;
}
// dfs and similar