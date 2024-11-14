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
	vector<vector<int>> g(2*n), rg(2*n);
	for(int i=1; i<=m; i++)
	{
		int a, va, b, vb; cin>>a>>va>>b>>vb;
		a--, b--;// use 0-indexed
		g[a+n*(va&1)].eb(b+n*(vb^1));
		g[b+n*(vb&1)].eb(a+n*(va^1));
		rg[b+n*(vb^1)].eb(a+n*(va&1));
		rg[a+n*(va^1)].eb(b+n*(vb&1));
	}
	vector<bool> vis(2*n);
	vector<int> ord, col(2*n);
	ord.resize(2*n); int cnt=0;
	function<void(int)> dfs1=[&](int u)
	{
		vis[u]=true;
		each(v, g[u]) if(!vis[v])
			dfs1(v);
		ord.eb(u);
	};
	function<void(int)> dfs2=[&](int u)
	{
		col[u]=cnt;
		each(v, rg[u]) if(!col[v])
			dfs2(v);
	};
	for(int i=0; i<2*n; i++) if(!vis[i])
		dfs1(i);
	reverse(all(ord));
	each(i, ord) if(!col[i])
		cnt++, dfs2(i);
	for(int i=0; i<n; i++)
		if(col[i]==col[i+n])
			return cout<<"IMPOSSIBLE"<<endl, 0;
	cout<<"POSSIBLE"<<endl;
	for(int i=0; i<n; i++)
		cout<<(col[i]>col[i+n])<<" ";
	return 0;
}