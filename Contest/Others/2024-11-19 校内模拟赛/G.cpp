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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>; 

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=3010, mod=1e9+7;

int n;
ll a[N], s[N][N], f[N][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i], a[i]+=a[i-1];
	s[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			f[i][j]=s[a[i]%j][j-1];
			(s[a[i]%j][j-1]+=f[i][j-1])%=mod;
		}
	}
	ll ans=0;
	for(int i=1; i<=n; i++)
		(ans+=f[n][i])%=mod;
	cout<<ans<<endl;
	return 0;
}
// dp