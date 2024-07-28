// Problem: D - K-th Nearest
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(all(a));
	for(int i=1; i<=q; i++)
	{
		int x, k;
		cin>>x>>k;
		int l=0, r=2e8, ans=2e8;
		auto check=[&](int p)
		{
			int l=x-p, r=x+p;
			return distance(lower_bound(all(a), l), 
			upper_bound(all(a), r))>=k;
		};
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) r=mid-1, ans=mid;
			else l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
