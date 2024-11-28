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
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        unordered_map<string, int> hs;
        vector<pii> a(n); 
        int tot=0;
        for(int i=0; i<n; i++)
        {
            string s, t; cin>>s>>t;
            a[i].fi=hs.count(s) ? hs[s] : hs[s]=++tot;
            a[i].se=hs.count(t) ? hs[t] : hs[t]=++tot;
        }
        // for(int i=0; i<n; i++) debug(a[i].fi);
        vector<vector<bool>> f(1<<n, vector<bool>(n));
        for(int i=0; i<n; i++) f[1<<i][i]=true;
        for(int i=0; i<(1<<n); i++) for(int j=0; j<n; j++)
            if((i>>j)&1 && f[i][j])
                for(int k=0; k<n; k++)
                    if(!((i>>k)&1) && (a[j].fi==a[k].fi || a[j].se==a[k].se))
                        f[i|(1<<k)][k]=true;
        int res=n;
        for(int i=0; i<(1<<n); i++) for(int j=0; j<n; j++)
            if(f[i][j])
                cmin(res, n-__builtin_popcount(i));
        cout<<res<<endl;
    }
	return 0;
}
// dp, bitmasks