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

ll qmi(ll a, ll k, ll p)
{
    a%=p;
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}

signed main()
{
	setIO();
	int T; cin>>T;
    while(T--)
    {
        ll k, l, r, p; cin>>k>>l>>r>>p;
        if(p==2){ cout<<!(k&1)<<endl; continue; }
        if(k%p==0)
        {
            cout<<(k&1 ? qmi((p+1)/2, r-l, p) : 1)<<endl;
            continue;
        }
    }
	return 0;
}
// math