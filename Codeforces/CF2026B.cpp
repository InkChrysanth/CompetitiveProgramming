//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n;
		vector<ll> a(n);
		each(x, a) cin>>x;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		ll l=1, r=1e18, res=r;
		auto check=[&](ll x)
		{
			if(n&1)
			{
				bool res=false;
				for(int i=0; i<n; i++)
				{
					vector<ll> cand;
					for(int j=0; j<n; j++) if(j!=i)
						cand.eb(a[j]);
					bool flag=true;
					for(int j=1; j<cand.size(); j+=2)
						if(cand[j]-cand[j-1]>x)
							flag=false;
					res|=flag;
				}
				if(!res) return false;
			}
			else
			{
				for(int i=1; i<n; i+=2)
					if(a[i]-a[i-1]>x)
						return false;
			}
			return true;
		};
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid)) r=mid-1, res=mid;
			else l=mid+1;
		}
		cout<<res<<endl;
	}
	return 0;
}
// binary search, brute force