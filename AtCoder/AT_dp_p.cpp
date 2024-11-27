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
constexpr int mod=1e9+7;

signed main()
{
	setIO();
	int n; cin>>n;
    vector<array<ll, 2>> f(n+1, {1, 1});
    vector<vector<int>> g(n+1);
    for(int i=1; i<n; i++)
    {
        int u, v; cin>>u>>v;
        g[u].eb(v); g[v].eb(u);
    }
    function<void(int, int)> dfs=[&](int u, int par)
    {
        each(v, g[u]) if(v!=par)
        {
            dfs(v, u);
            (f[u][0]*=(f[v][1]+f[v][0]))%=mod;
            (f[u][1]*=f[v][0])%=mod;
        }
    };
    dfs(1, 0);
    cout<<(f[1][0]+f[1][1])%mod<<endl;
	return 0;
}
// trees, dp