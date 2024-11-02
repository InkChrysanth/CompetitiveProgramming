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
constexpr int N=1000010;

signed main()
{
	setIO();
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n;
		vector<int> a(n+1);
		for(int i=1; i<=n; i++) cin>>a[i];
		vector<ll> s(n+1);
		for(int i=2; i<=n; i++) s[i]=(s[i-1]+(a[i]==a[i-1] ? a[i] : 0));
		vector<ll> f(n+1), lst(N);
		for(int i=1; i<=n; i++)
		{
			f[i]=f[i-1];
			if(lst[a[i]]) cmax(f[i], f[lst[a[i]]+1]+s[i]-s[lst[a[i]]+1]+a[i]);
			lst[a[i]]=i;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
// dp