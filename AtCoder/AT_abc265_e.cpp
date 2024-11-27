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
constexpr int N=310, mod=998244353;

int n, m;
ll a, b, c, d, e, f;
set<pll> ob;
ll dp[N][N][N];

signed main()
{
	setIO();
	cin>>n>>m;
	cin>>a>>b>>c>>d>>e>>f;
	for(int i=1; i<=m; i++)
	{
		int x, y; cin>>x>>y;
		ob.ins(mp(x, y));
	}
	dp[0][0][0]=1;
	for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) for(int k=0; k<=n; k++)
	{
		if(i+j+k>n) continue;
		if(ob.count(mp(i*a+j*c+k*e, i*b+j*d+k*f))) continue;
		if(i) dp[i][j][k]+=dp[i-1][j][k];
		if(j) dp[i][j][k]+=dp[i][j-1][k];
		if(k) dp[i][j][k]+=dp[i][j][k-1];
		dp[i][j][k]%=mod;
	}
	ll ans=0;
	for(int i=0; i<=n; i++) for(int j=0; j<=n; j++)
	{
		int k=n-i-j;
		(ans+=dp[i][j][k])%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
// dp, hashing