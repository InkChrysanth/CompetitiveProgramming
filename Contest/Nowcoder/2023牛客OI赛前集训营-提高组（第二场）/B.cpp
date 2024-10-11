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

int n, m, d; ll k;
struct SegmentTree
{
	ll sum[N<<2], lmx[N<<2], rmx[N<<2], ans[N<<2];
	void pushup(int u)
	{
		sum[u]=sum[u<<1]+sum[u<<1|1];
		lmx[u]=max(lmx[u<<1], sum[u<<1]+lmx[u<<1|1]);
		rmx[u]=max(rmx[u<<1|1], sum[u<<1|1]+rmx[u<<1]);
		ans[u]=max({ans[u<<1], ans[u<<1|1], rmx[u<<1]+lmx[u<<1|1]});
	}
	void build(int u, int l, int r)
	{
		if(l==r)
		{
			sum[u]=lmx[u]=rmx[u]=ans[u]=-k;
			return;
		}
		int mid=(l+r)>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
		pushup(u);
	}
	void modify(int u, int l, int r, int pos, ll val)
	{
		if(l==r && l==pos)
		{
			sum[u]+=val;
			lmx[u]+=val;
			rmx[u]+=val;
			ans[u]+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) modify(u<<1, l, mid, pos, val);
		else modify(u<<1|1, mid+1, r, pos, val);
		pushup(u);
	}
} sgt;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k>>d;
    sgt.build(1, 1, n);
	while(m--)
	{
		int pos; ll val;
		cin>>pos>>val;
		sgt.modify(1, 1, n, pos, val);
		cout<<(sgt.ans[1]<=k*d ? "YES" : "NO")<<endl;
	}
    return 0;
}
// data structures(SegmentTree), math