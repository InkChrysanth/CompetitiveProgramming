// Problem: F. Expected Median
// Contest: Codeforces - Codeforces Round 964 (Div. 4)
// URL: https://codeforces.com/contest/1999/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010, mod=1e9+7;

ll fac[N], invfac[N];

ll qmi(ll a, ll k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k=k>>1;
	}
	return res;
}

void init()
{
	fac[0]=1;
	for(int i=1; i<N; i++) fac[i]=fac[i-1]*i%mod;
	invfac[N-1]=qmi(fac[N-1], mod-2);
	for(int i=N-1; i>=1; i--) invfac[i-1]=invfac[i]*i%mod;
}

ll C(int n, int k)
{
	if(n<k) return 0;
	return fac[n]*invfac[k]%mod*invfac[n-k]%mod;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	init();
	while(T--)
	{
		int n, k, cnt=0;
		cin>>n>>k;
		vector<int> a(n+1);
		for(int i=1; i<=n; i++) cin>>a[i], cnt+=a[i];
		ll ans=0;
		for(int i=k/2+1; i<=k; i++)
			(ans+=C(cnt, i)*C(n-cnt, k-i))%=mod;
		cout<<ans<<endl;
	}
	return 0;
}
