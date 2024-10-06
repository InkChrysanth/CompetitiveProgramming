#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using lll=__int128;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

signed main()
{
	// cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	vector<pair<lll, int>> a(n+1);
	for(int i=1; i<=n; i++)
		a[i].fi=read(), a[i].se=i;
	vector<int> p(n+1), sz(n+1, 1);
	vector<lll> mx(n+1);
	iota(p.begin()+1, p.begin()+n+1, 1);
	function<int(int)> find=[&](int x){ return x==p[x] ? x : p[x]=find(p[x]); };
	auto merge=[&](int x, int y)
	{
		int fx=find(x), fy=find(y);
		if(fx!=fy)
		{
			p[fy]=fx;
			sz[fx]+=sz[fy];
			cmax(mx[fx], mx[fy]);
		}
	};
	sort(a.begin()+1, a.begin()+n+1, greater<pair<lll, int>>());
	vector<bool> vis(n+1);
	lll ans=0;
	for(int i=1; i<=n; i++)
	{
		vis[a[i].se]=true;
		mx[a[i].se]=a[i].fi;
		if(vis[a[i].se-1]) merge(a[i].se, a[i].se-1);
		if(vis[a[i].se+1]) merge(a[i].se, a[i].se+1);
		int u=find(a[i].se);
		cmax(ans, sz[u]*mx[u]*a[i].fi);
	}
	print(ans);
	return 0;
}
// dsu, greedy