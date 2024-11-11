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
using lll=__int128;
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
constexpr int N=200010, K=63, mod=1e9+7;

int n, q; ll m;
string s;
lll f[N][K];
ll sum[N];

signed main()
{
	setIO();
	cin>>n>>m>>q>>s;
	s="%"+s+s;
	for(int i=1; i<=n; i++)
		sum[i]=sum[i-1]+(s[i]-'0');
	auto mod_n=[](lll x){ return x%n==0 ? n : x%n; };
	auto ask=[&](ll x)
	{ return sum[x%n]+(x/n)*sum[n]; };
	auto query=[&](ll l, ll r)
	{ return ask(r)-ask(l-1); };
	for(int i=1; i<=n; i++)
	{
		ll l=i+1, r=i+m, res=l;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(query(mid, i+m)) res=mid, l=mid+1;
			else r=mid-1;
		}
		if(sum[mod_n(res)]-sum[mod_n(res-1)]) f[i][0]=res-i;
		else f[i][0]=1;
	}
	for(int k=1; k<K; k++) for(int i=1; i<=n; i++)
		f[i][k]=f[i][k-1]+f[mod_n(i+f[i][k-1])][k-1];
	while(q--)
	{
		ll a, b; cin>>a>>b;
		ll res=a%mod;
		for(int k=K-1; k>=0; k--)
		{
			if((b>>k)&1)
			{
				a=mod_n(a);
				res=(res+f[a][k]%mod)%mod;
				a+=mod_n(f[a][k]);// - f[a][k]%mod
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
// binary lifting, binary search