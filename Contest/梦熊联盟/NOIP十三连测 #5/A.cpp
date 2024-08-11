//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".ans")
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

signed main()
{
	Fre("or");
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	function<ll(ll, ll)> solve=[&](ll a, ll b) -> ll
	{
		if(a==b) return 1;
		int x=__lg(a), y=__lg(b);
		if(x==y) return solve(a-(1ll<<x), b-(1ll<<y));
		ll c=b-(1ll<<y);
		ll l1=a, r1=(1ll<<y)-1;
		ll l2=0, r2=0;
		if(c) r2=(1ll<<(__lg(c)+1))-1;
		if(l1>r2) return r1-l1+1+r1-l1+1+r2-l2+1;
		return r1-l1+1+r1+1;
	};
	for(ll l, r; T>=1; T--)
	{
		cin>>l>>r;
		cout<<solve(l, r)<<endl;
	}
	return 0;
}
