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
using pdd=pair<ld, ld>;

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
constexpr ld eps=1e-8;

signed main()
{
	setIO();
	int T; cin>>T;
    while(T--)
    {
        int n, m; cin>>n>>m;
        vector<pdd> pigs(n);
        each(coord, pigs) cin>>coord.fi>>coord.se;
        auto work=[&](pdd c0, pdd c1) -> pdd
        {
            return mp((c1.fi*c0.se-c0.fi*c1.se)/(c0.fi*c0.fi*c1.fi-c0.fi*c1.fi*c1.fi), 
            (c1.se*c0.fi*c0.fi-c0.se*c1.fi*c1.fi)/(c0.fi*c0.fi*c1.fi-c0.fi*c1.fi*c1.fi));
        };
        vector<int> cand;
        each(c0, pigs) each(c1, pigs) if(abs(c0.fi-c1.fi)>eps)
        {
            auto res=work(c0, c1);
            // debug(res.fi);
            if(res.fi>=0) continue;
            cand.eb(0);
            for(int i=0; i<pigs.size(); i++)
            {
                auto c2=pigs[i];
                if(abs(res.fi*c2.fi*c2.fi+res.se*c2.fi-c2.se)<=eps)
                cand.back()|=(1<<i);
            }
        }
        vector<int> f(1<<n, inf);
        f[0]=0;
        for(int i=0; i<(1<<n); i++)
        {
            each(st, cand) cmin(f[i|st], f[i]+1);
            for(int j=0; j<n; j++) cmin(f[i|(1<<j)], f[i]+1);
        }
        cout<<f[(1<<n)-1]<<endl;
    }
	return 0;
}
// dp, math, bitmasks