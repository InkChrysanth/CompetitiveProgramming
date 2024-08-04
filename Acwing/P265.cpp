// Problem: 营业额统计
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/267/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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
	int n, ans;
	cin>>n>>ans;
	set<int> tr;
	tr.insert(ans);
	tr.insert(-inf);
	tr.insert(inf);
	for(int i=2; i<=n; i++)
	{
		int x; cin>>x;
		auto ptr=tr.lower_bound(x);
		int res=min(abs(*ptr-x), abs(*prev(ptr)-x));
		ans+=res;
		tr.insert(x);
	}
	cout<<ans<<endl;
	return 0;
}
