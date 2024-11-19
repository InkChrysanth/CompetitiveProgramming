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
    cout<<fixed<<setprecision(3);
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
constexpr int K=31;


signed main()
{
	setIO();
    int n; cin>>n;
    vector<pii> p(n+1);
    for(int i=1; i<=n; i++) cin>>p[i].fi>>p[i].se;
    auto work=[&](pii a, pii b) -> ld
    { return sqrt(1.0*(a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se)); };
    vector<array<ld, 31>> f(n+1);
    for(int i=1; i<=n; i++) for(int k=0; k<K; k++)
        f[i][k]=1e20;
    f[1][0]=0;
    for(int i=2; i<=n; i++)
    {
        for(int j=max(1, i-30); j<i; j++)
            for(int k=0; k<=min(i-1, 30); k++)
                if(k-(i-j-1)>=0)
                    cmin(f[i][k], f[j][k-(i-j-1)]+work(p[i], p[j]));
    }
    ld ans=1e20;
    for(int i=0; i<K; i++) cmin(ans, f[n][i]+(i==0 ? 0 : pow(2, i-1)));
    cout<<ans<<endl;
	return 0;
}
// dp