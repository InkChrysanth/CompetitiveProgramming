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
        int n, q; cin>>n>>q;
        vector<ll> a(2*n+1);
        for(int i=1; i<=n; i++) cin>>a[i], a[i+n]=a[i];
        vector<ll> s(2*n+1);
        for(int i=1; i<=2*n; i++) s[i]=s[i-1]+a[i];
        auto get=[&](ll x)
        { return (x+n-1)/n; };
        auto work=[&](ll l, ll r, ll x)
        {
            return s[x+((l-1)%n)+r-l]-s[x+((l-1)%n)-1];
        };
        while(q--)
        {
            ll l, r; cin>>l>>r;
            ll ql=get(l), qr=get(r);
            // debug(ql); debug(qr);
            if(ql==qr)
            {
                // ql+((l-1)%n) len: r-l
                cout<<s[ql+((l-1)%n)+r-l]-s[ql+((l-1)%n)-1]<<endl;
            }
            else
            {
                ll res=0;
                res+=(qr-ql-1)*s[n];
                // debug(res);
                res+=work(l, n*ql, ql);
                // debug(res);
                res+=work((qr-1)*n+1, r, qr);
                // debug(res);
                // debug("xxxx");
                cout<<res<<endl;
            }
        }
    }
	return 0;
}
// math, prefix sum, bitmasks