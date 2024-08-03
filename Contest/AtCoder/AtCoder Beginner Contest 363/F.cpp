// Problem: F - Palindromic Expression
// Contest: AtCoder - AtCoder Beginner Contest 363
// URL: https://atcoder.jp/contests/abc363/tasks/abc363_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	cin>>n;
	auto check=[&](ll x)
	{
		if(x==0) return 0;
		while(x)
		{
			if(x%10==0) return 0;
			x/=10;
		}
		return 1;
	};
	auto rev=[&](ll x)
	{
		string s=to_string(x);
		string rs(s.rbegin(), s.rend());
		return stoll(rs);
	};
	function<string(ll)> dfs=[&](ll n)
	{
		if(check(n) && rev(n)==n) return to_string(n);
		for(int i=2; i<=n/i; i++)
		{
			if(n%i==0 && check(i))
			{
				int j=rev(i);
				if((n/i)%j) continue;
				string res=dfs(n/i/j);
				if(res!="-1") return to_string(i)+"*"+res+"*"+to_string(j);
			}
		}
		return (string)"-1";
	};
	cout<<dfs(n)<<endl;
	return 0;
}
