// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
	int n; cin>>n; ll sum=0;
	vector<ll> a(n+1);
	for(int i=1; i<=n; i++) cin>>a[i], sum+=a[i];
	ll ans=0; array<ll, 2> b={0, 0};// b_0: max  b_1: sub-max
	for(int i=1; i<=n; i++)
	{
		if(a[i]>sum/3) return cout<<-1<<endl, 0;
		ans+=a[i]/2;
		if(a[i]/2>b[0]) b[1]=b[0]/*alert: notice the order*/, b[0]=a[i]/2;
		else if(a[i]/2>b[1]) b[1]=a[i]/2;
	}
	debug(b[0]); debug(b[1]);
	while(true)
	{
		bool flag=true;
		for(int i=0; i<=1; i++)
		{
			if(b[i]*3>ans)
			{
				flag=false;
				ll x=(3*b[i]-ans+1)/2;
				b[i]-=x, ans-=x;
			}
		}
		if(flag) break;
	}
	cout<<min(ans/3, sum/9)<<endl;
	return 0;
}
// math, implementation