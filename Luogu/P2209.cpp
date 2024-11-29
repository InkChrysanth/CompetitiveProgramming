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
    ll n, g, b, d; cin>>n>>g>>b>>d;
    vector<pll> gs(n+1);
    gs[n]=mp(d, 0);
    for(int i=0; i<n; i++) cin>>gs[i].fi>>gs[i].se;
    sort(all(gs));
    for(int i=0; i<n-1; i++) if(g<gs[i+1].fi-gs[i].fi)
        return cout<<-1<<endl, 0;
    if(b<gs[0].fi) return cout<<-1<<endl, 0;
    deque<pll> q;
    q.push_back(mp(b, 0));
    ll ng=b, ans=0;
    for(int i=0; i<=n; i++)
    {
        // each(x, q) cerr<<x.fi<<" "<<x.se<<endl;
        // cerr<<ans<<endl;
        ll cost=(!i ? gs[i].fi : gs[i].fi-gs[i-1].fi);
        while(cost>0)
        {
            auto t=q.front(); q.pop_front();
            if(t.fi>cost)
            {
                ng-=cost;
                q.push_front(mp(t.fi-cost, t.se));
                break;
            }
            cost-=t.fi, ng-=t.fi;
        }
        while(q.size() && q.back().se>gs[i].se)
        {
            // debug(gs[i].se);
            auto t=q.back(); q.pop_back();
            ans-=t.fi*t.se;
            ng-=t.fi;
        }
        ans+=(g-ng)*gs[i].se;
        q.push_back(mp(g-ng, gs[i].se));
        ng=g;
    }
    cout<<ans<<endl;
	return 0;
}
// greedy, data structures