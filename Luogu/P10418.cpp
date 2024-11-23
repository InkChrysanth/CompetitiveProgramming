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
	int n; cin>>n;
    vector<vector<pii>> g(n+1);
    for(int i=2; i<=n; i++)
    {
        int x, y; cin>>x>>y;
        g[i].eb(mp(x, y));
        g[x].eb(mp(i, y));
    }
    ll ans=0;
    for(int i=1; i<=n; i++) if(g[i].size()>=3)
    {
        sort(all(g[i]), [](pii x, pii y){ return x.se>y.se; });
        cmax(ans, (ll)g[i][0].se+g[i][1].se+g[i][2].se);
    }
    for(int i=1; i<=n; i++) if(g[i].size()>=2)
    {
        sort(all(g[i]), [](pii x, pii y){ return x.se>y.se; });
        each(t, g[i]) if(g[t.fi].size()>=2)
        {
            ll res=0;
            sort(all(g[t.fi]), [](pii x, pii y){ return x.se>y.se; });
            res+=t.se;
            res+=(g[t.fi][0].fi!=i ? g[t.fi][0].se : g[t.fi][1].se);
            res+=(g[i][0].fi!=t.fi ? g[i][0].se : g[i][1].se);
            cmax(ans, res);
        }  
    }
    cout<<ans<<endl;
	return 0;
}
// trees, graphs, brute force, sortings