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
	string str; cin>>str;
	vector<int> pos;
	for(int i=0; i<str.size(); i++)
		if(str[i]=='1')
			pos.eb(i);
	if(pos.empty() || pos.back()-pos.front()==pos.size()-1)
		return cout<<0<<endl, 0;
	int l=0, r=pos.size(), res=r;
	auto check=[&](int mid) -> bool
	{
		int k=pos.size(), x=k-mid;
		for(int i=0; i<mid; i++)
		{
			int l=pos[i], r=pos[i+x-1];
			if(r-l+1-x<=mid)	
				return true;
		}
		return false;
	};
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1, res=mid;
		else l=mid+1;
	}
	cout<<res<<endl;
	return 0;
}
// binary search