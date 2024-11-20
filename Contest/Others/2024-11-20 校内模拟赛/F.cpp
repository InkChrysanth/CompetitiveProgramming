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
constexpr int N=200010, mod=1e9+7;

ll qmi(ll a, ll k)
{
	ll res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

ll f[N], inv[N], p2[N];
void init()
{
    p2[0]=1;
    for(int i=1; i<N; i++) p2[i]=p2[i-1]*2%mod;
	f[0]=inv[0]=1;
	for(int i=1; i<N; i++) f[i]=(f[i-1]*i)%mod;
	inv[N-1]=qmi(f[N-1], mod-2);
	for(int i=N-1; i>=1; i--) inv[i-1]=(inv[i]*i)%mod; 
}

ll C(int a, int b)
{
	if(a<0 || b<0 || a<b) return 0;
	return f[a]*inv[b]%mod*inv[a-b]%mod;
}

signed main()
{
    setIO(); init();
	int n, k; cin>>n>>k;
    vector<ll> a(n+1), sum(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a.begin()+1, a.begin()+n+1);
    for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
    ll ans=0;
    for(int i=1; i<=n; i++)
        ans=(ans+(a[i]*(i-1)%mod-sum[i-1]%mod+mod)%mod*C(n-2, k-2)%mod)%mod;
    cout<<ans<<endl;
	return 0;
}
// math, prefix sum