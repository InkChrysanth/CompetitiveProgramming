// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010;

int h, w, n;
pii a[N];
int pre[N];
string ans;

struct Fenwick
{
	pii t[N];// fi: value	se: pos
	Fenwick(){ for(int i=0; i<N; i++) t[i]=mp(0, 0); }
	int lowbit(int x){ return x&-x; }
	void modify(int x, pii v){ for(; x<=w; x+=lowbit(x)) cmax(t[x], v); }
	pii query(int x)
	{
		pii res=mp(0, 0);
		for(; x; x-=lowbit(x)) cmax(res, t[x]);
		return res;
	}
} tr;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>h>>w>>n;
	a[0]=mp(1, 1); a[++n]=mp(h, w); 
    for(int i=1, x, y; i<n; i++)
    {
    	cin>>x>>y;
    	a[i]=mp(x, y);
	}
	sort(a+1, a+n);
	for(int i=1; i<=n; i++)
	{
		auto res=tr.query(a[i].se);
		pre[i]=res.se;
		tr.modify(a[i].se, mp(res.fi+1, i));
	}
	for(int i=n; i; i=pre[i])
	{
		int d=a[i].fi-a[pre[i]].fi, r=a[i].se-a[pre[i]].se;
		while(d--) ans.pb('D');
		while(r--) ans.pb('R');
	}
	reverse(all(ans));
	cout<<tr.query(w).fi-1<<endl<<ans<<endl;
	return 0;
}
