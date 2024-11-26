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
constexpr int N=200010;

int lowbit(int x){ return x&-x; }
struct Fenwick1
{
    ll a[N];
    Fenwick1(){ memset(a, 0xc0, sizeof a); }
    void modify(int x, ll v)
    { for(; x<N; x+=lowbit(x)) cmax(a[x], v); }
    ll query(int x)
    { ll res=-llinf; for(; x; x-=lowbit(x)) cmax(res, a[x]); return res; }
} tr1;
struct Fenwick2
{
    ll a[N];
    Fenwick2(){ memset(a, 0xc0, sizeof a); }
    void modify(int x, ll v)
    { for(; x; x-=lowbit(x)) cmax(a[x], v); }
    ll query(int x)
    { ll res=-llinf; for(; x<N; x+=lowbit(x)) cmax(res, a[x]); return res; }
} tr2;

int n, m, c; 
ll f[N];

signed main()
{
	setIO();
	cin>>n>>c>>m;
    tr1.modify(1, c);
    tr2.modify(1, -c);
    ll ans=0;
    for(int i=1; i<=m; i++)
    {
        ll t, p; cin>>t>>p;
        ll t1=tr1.query(t)-t*c, t2=tr2.query(t)+t*c;
        f[i]=max(t1, t2)+p; cmax(ans, f[i]);
        tr1.modify(t, f[i]+t*c);
        tr2.modify(t, f[i]-t*c);
    }
    cout<<ans<<endl;
	return 0;
}
// dp, data structures