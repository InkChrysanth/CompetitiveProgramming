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

int n, q;
ll a[N];
ll ans=0;

struct SegmentTree
{
	ll sum[N<<3], tag[N<<3];
	ll lb[N<<3], rb[N<<3];
	void pushup(int u){ sum[u]=sum[u<<1]+sum[u<<1|1]; }
	void pushdown(int u)
	{
		if(tag[u]==-inf) return;
		sum[u<<1]=(tag[u]+(tag[u]+rb[u<<1]-lb[u<<1]))*(rb[u<<1]-lb[u<<1]+1)/2;
		sum[u<<1|1]=((rb[u<<1]-lb[u<<1]+1+tag[u])+(rb[u<<1|1]-lb[u<<1]+tag[u]))*(rb[u<<1|1]-lb[u<<1|1]+1)/2;
		tag[u<<1]=tag[u];
		tag[u<<1|1]=tag[u]+(rb[u<<1]-lb[u<<1]+1);
		tag[u]=-inf;
	}
	void build(int u, int l, int r)
	{
		lb[u]=l, rb[u]=r;
		tag[u]=-inf;
		if(l==r)
		{
			sum[u]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
		pushup(u);
	}
	void modify(int u, int l, int r, ll val)
	{
		if(l>rb[u] || r<lb[u]) return;
		if(l<=lb[u] && r>=rb[u])
		{
			sum[u]=(val+(val+rb[u]-lb[u]))*(rb[u]-lb[u]+1)/2;
			tag[u]=val;
			return;
		}
		pushdown(u);
		modify(u<<1, l, r, val);
		modify(u<<1|1, l, r, val+max(0ll, rb[u<<1]-max((ll)l, lb[u<<1])+1));
		pushup(u);
	}
	ll query(int u, int l, int r)
	{
		if(l>rb[u] || r<lb[u]) return 0;
		if(l<=lb[u] && r>=rb[u]) return sum[u];
		pushdown(u);
		return query(u<<1, l, r)+query(u<<1|1, l, r);
	}
} sgt;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sgt.build(1, 1, n);
	cin>>q;
	while(q--)
	{
		ll pos, tar;
		cin>>pos>>tar;
		ll cur=sgt.query(1, pos, pos);
		if(cur>tar)
		{
			ll l=1, r=pos, res=pos;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(sgt.query(1, mid, mid)<tar+mid-pos) l=mid+1;
				else r=mid-1, res=mid;
			}
			ans+=(sgt.query(1, res, pos)-tar*(pos-res+1)+(pos-res)*(pos-res+1)/2);
			sgt.modify(1, res, pos, tar-pos+res);
		}
		else
		{
			ll l=pos, r=n, res=pos;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(sgt.query(1, mid, mid)>tar+mid-pos) r=mid-1;
				else l=mid+1, res=mid;
			}
			ans+=(-sgt.query(1, pos, res)+(tar+(tar+res-pos))*(res-pos+1)/2);
			sgt.modify(1, pos, res, tar);
		}
	}
	cout<<ans<<endl;
	return 0;
}
