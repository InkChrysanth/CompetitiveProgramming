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
	vector<vector<int>> g(2*n+1);
	auto work=[&](int x)
	{ return x&1 ? x+1 : x-1; };
	for(int i=1; i<=m; i++)
	{
		int u, v; cin>>u>>v;
		g[u].eb(work(v));
		g[v].eb(work(u));
	}
	int dn=0, cnt=0;
	vector<int> low(2*n+1), dfn(2*n+1), col(2*n+1);
	stack<int> S; vector<bool> vis(2*n+1);
	function<void(int)> tarjan=[&](int u)
	{
		low[u]=dfn[u]=++dn;
		S.push(u); vis[u]=true;
		each(v, g[u])
		{
			if(!dfn[v])
			{
				tarjan(v);
				cmin(low[u], low[v]);
			}
			else if(vis[v]) cmin(low[u], dfn[v]);
		}
		if(low[u]==dfn[u])
		{
			cnt++;
			do
			{
				u=S.top(); S.pop();
				col[u]=cnt;
				vis[u]=false;
			} while(low[u]!=dfn[u]);
		}
	};
	for(int i=1; i<=2*n; i++) if(!dfn[i])
		tarjan(i);
	for(int i=1; i<2*n; i+=2)
		if(col[i]==col[i+1])
			return cout<<"NIE"<<endl, 0;
	for(int i=1; i<2*n; i+=2)
		cout<<(col[i]<col[i+1] ? i : i+1)<<endl;// reversed
	return 0;
}
// 2-SAT graphs(tarjan)