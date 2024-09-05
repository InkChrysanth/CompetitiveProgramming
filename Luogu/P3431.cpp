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
constexpr int N=100010;

int h, w, n;
pair<pii, int> a[N];
int p[N], q[N];

struct Fenwick
{
	int t[N];
	Fenwick(){ for(int i=0; i<N; i++) t[i]=0; }
	int lowbit(int x){ return x&-x; }
	void modify(int x, int v){ for(; x<=w; x+=lowbit(x)) cmax(t[x], v); }
	int query(int x)
	{
		int res=0;
		for(; x; x-=lowbit(x)) cmax(res, t[x]);
		return res;
	}
} tr;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>h>>w>>n;
	a[0]=mp(mp(1, 1), 0); a[++n]=mp(mp(h, w), 0);
	p[0]=1, q[0]=1, p[n]=h, q[n]=w;
    for(int i=1, x, y, v; i<n; i++)
    {
    	cin>>x>>y>>v;
    	a[i]=mp(mp(x, y), v);
    	p[i]=x, q[i]=y;
	}
	map<int, int> hs1, hs2;
	sort(p+1, p+n), sort(q+1, q+n);
	int px=1, py=1;
	hs1[p[0]]=px, hs2[q[0]]=py;
	for(int i=1; i<=n; i++)
	{
		if(p[i]!=p[i-1]) hs1[p[i]]=++px;
		if(q[i]!=q[i-1]) hs2[q[i]]=++py;
	}
	h=px, w=py;
	for(int i=0; i<=n; i++)
	{
		a[i].fi.fi=hs1[a[i].fi.fi];
		a[i].fi.se=hs2[a[i].fi.se];
	}
	sort(a+1, a+n);
	for(int i=1; i<=n; i++)
		tr.modify(a[i].fi.se, tr.query(a[i].fi.se)+a[i].se);
	cout<<tr.query(w)<<endl;
	return 0;
}
