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
constexpr int mod=998244353;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin>>n>>m>>k;
    vector<pii> E;
    set<int> S;
    for(int i=0, u, v; i<m; i++)
    {
        cin>>u>>v;
        u--, v--;//use 0-indexed
        E.eb(u, v);
        S.em(u), S.em(v);
    }
    vector<int> id(n); int tot=0;
    each(u, S) id[u]=tot++;
    deque<ll> f(n); f[0]=1;
    while(k--)
    {
        vector<ll> det(tot);
        each(e, E) det[id[e.se]]=(det[id[e.se]]+f[e.fi])%mod;
        f.push_front(f.back()); f.pop_back();
        each(u, S) f[u]=(f[u]+det[id[u]])%mod;
    }
    ll ans=0;
    each(val, f) ans=(ans+val)%mod;
    cout<<ans<<endl;
	return 0;
}