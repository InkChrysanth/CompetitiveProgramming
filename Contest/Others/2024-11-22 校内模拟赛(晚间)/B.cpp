//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,n) (i)=min((i),(n))
#define cmax(i,n) (i)=max((i),(n))
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
    vector<vector<pii>> g(n+1);
    for(int i=1; i<=m; i++)
    {
        int u, v; char w; cin>>u>>v>>w;
        g[u].eb(mp(v, (int)w));
        g[v].eb(mp(u, (int)w));
    }
    vector<vector<int>> f(n+1, vector<int>(n+1, inf));
    f[1][n]=0;
    queue<pii> q; q.push(mp(1, n));
    while(q.size())
    {
        auto t=q.front(); q.pop();
        each(e1, g[t.fi]) each(e2, g[t.se])
            if(e1.se==e2.se && f[e1.fi][e2.fi]==inf)
            {
                f[e1.fi][e2.fi]=f[t.fi][t.se]+2;
                if(e1.fi!=e2.fi) q.push(mp(e1.fi, e2.fi));
            }
    }
    int ans=inf;
    for(int i=1; i<=n; i++) cmin(ans, f[i][i]);
    for(int i=1; i<=n; i++) each(t, g[i])
        cmin(ans, f[i][t.fi]+1);
    cout<<(ans==inf ? -1 : ans)<<endl;
	return 0;
}
// bfs and similar, graphs