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
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=30010, M=200010, D=100000;

int n, s;
pii seg[N];
int f[N][2];

struct SegmentTree
{
	int lst[M<<2], tag[M<<2];
	void pushdown(int u)
	{
		if(!tag[u]) return;
		lst[u<<1]=lst[u<<1|1]=lst[u];
		tag[u<<1]=tag[u<<1|1]=tag[u];
		tag[u]=0;
	}
	void build(int u=1, int l=0, int r=D<<1)
	{
		if(l==r){ lst[u]=tag[u]=0; return; }
		int mid=(l+r)>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
	}
	void modify(int ql, int qr, int val, int u=1, int l=0, int r=D<<1)
	{
		if(ql<=l && qr>=r){ lst[u]=tag[u]=val; return; }
		pushdown(u);
		int mid=(l+r)>>1;
		if(ql<=mid) modify(ql, qr, val, u<<1, l, mid);
		if(qr>mid) modify(ql, qr, val, u<<1|1, mid+1, r);
	}
	int query(int pos, int u=1, int l=0, int r=D<<1)
	{
		if(l==r) return lst[u];
		pushdown(u);
		int mid=(l+r)>>1;
		if(pos<=mid) return query(pos, u<<1, l, mid);
		else return query(pos, u<<1|1, mid+1, r);
	}
}sgt;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>s; s+=D;
	seg[0]=mp(D, D);
	for(int i=1, l, r; i<=n; i++)
	{
		cin>>l>>r;
		seg[i]=mp(l+D, r+D);
	}
	sgt.build();
	for(int i=1; i<=n; i++)
	{
		int pl=sgt.query(seg[i].fi), pr=sgt.query(seg[i].se);
		f[i][0]=min(f[pl][0]+abs(seg[i].fi-seg[pl].fi), f[pl][1]+abs(seg[i].fi-seg[pl].se));
		f[i][1]=min(f[pr][0]+abs(seg[i].se-seg[pr].fi), f[pr][1]+abs(seg[i].se-seg[pr].se));
		sgt.modify(seg[i].fi, seg[i].se, i);
	}
	cout<<min(f[n][0]+abs(seg[n].fi-s), f[n][1]+abs(seg[n].se-s))<<endl;
	return 0;
}
