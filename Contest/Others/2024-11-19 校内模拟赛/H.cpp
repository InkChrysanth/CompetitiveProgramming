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
constexpr int N=1000010, mod=998244353;

ll qmi(ll a, ll k)
{
	a%=mod;
	ll res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res%mod;
}

ll f[N], inv[N];
void init()
{
	f[0]=inv[0]=1;
	for(int i=1; i<N; i++) f[i]=(f[i-1]*i)%mod;
	inv[N-1]=qmi(f[N-1], mod-2)%mod;
	for(int i=N-1; i>=1; i--) inv[i-1]=(inv[i]*i)%mod; 
}

struct Point
{
	array<int, 11> p;
	bool operator<(const Point &T)const
	{
		for(int i=1; i<=10; i++)
			if(p[i]!=T.p[i])
				return p[i]<T.p[i];
		return false;
	}
};

signed main()
{
	setIO(); init();
	int k, n; cin>>k>>n;
	vector<Point> a(n+2); 
	for(int j=1; j<=k; j++)
		cin>>a[n+1].p[j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
			cin>>a[i].p[j];
	sort(a.begin()+1, a.begin()+n+2);
	auto work=[&](array<int, 11> p1, array<int, 11> p2) -> ll
	{
		for(int i=1; i<=k; i++)
			if(p2[i]<p1[i])
				return 0;
		ll sum=0;
		for(int i=1; i<=k; i++)
			sum+=(p2[i]-p1[i]);
		sum=f[sum];
		for(int i=1; i<=k; i++)
			(sum*=inv[p2[i]-p1[i]])%=mod;
		return sum%mod;
	};
	vector<ll> dp(n+2);
	for(int to=1; to<=n+1; to++)
	{
		dp[to]=work(a[0].p, a[to].p)%mod;
		for(int from=1; from<to; from++)
			dp[to]=(dp[to]-(dp[from]*work(a[from].p, a[to].p)%mod)+mod)%mod;
	}
	cout<<dp[n+1]<<endl;
	return 0;
}
// dp, math