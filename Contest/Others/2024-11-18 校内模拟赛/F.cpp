#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")

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
	int n, k; cin>>n>>k;
    vector<int> a(n+1);
	vector<int> tmp;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		tmp.eb(a[i]);
	}
	sort(all(tmp));
	tmp.erase(unique(all(tmp)), tmp.end());
	for(int i=1; i<=n; i++)
		a[i]=lower_bound(all(tmp), a[i])-tmp.begin();
	vector<vector<int>> p(tmp.size());
	for(int i=1; i<=n; i++)
		p[a[i]].eb(i);
	int l=0; ll ans=0;
	for(int i=1; i<=n; i++)
	{
		int num=a[i];
		auto ptr=lower_bound(all(p[num]), i);
		// cerr<<i<<" "<<l<<endl;
		if(ptr-p[num].begin()>=k-1) cmax(l, *prev(ptr, k-1));
		ans+=l;
	}
	cout<<ans<<endl;
	return 0;
}
// binary search