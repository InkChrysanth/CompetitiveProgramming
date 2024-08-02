// Problem: P3370 【模板】字符串哈希
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3370
// Memory Limit: 128 MB
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
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=10010;
constexpr ull base=233, p1=998244353, p2=1000000007;

pair<ull, ull> a[N];

ull hash1(string s)
{
	ull res=0;
	for(auto c: s) res=(res*base+(ull)c)%p1;
	return res;
}

ull hash2(string s)
{
	ull res=0;
	for(auto c: s) res=(res*base+(ull)c)%p2;
	return res;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		string s; cin>>s;
		a[i].fi=hash1(s);
		a[i].se=hash2(s);
	}
	sort(a+1, a+n+1);
	int ans=1;
	for(int i=2; i<=n; i++)
		if(a[i-1].fi!=a[i].fi || a[i-1].se!=a[i].se)
			ans++;
	cout<<ans<<endl;
	return 0;
}