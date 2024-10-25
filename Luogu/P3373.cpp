//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010, mod=571373;

int a[N];
struct SegmentTree
{
	ll sum[N<<2], add[N<<2], mul[N<<2];
	int L[N<<2], R[N<<2];
	void pushup(int u){ sum[u]=(sum[u<<1]+sum[u<<1|1])%mod; }
	void pushdown(int u)
	{
        sum[u<<1]=(sum[u<<1]*mul[u]+add[u]*(R[u<<1]-L[u<<1]+1))%mod;
		sum[u<<1|1]=(sum[u<<1|1]*mul[u]+add[u]*(R[u<<1|1]-L[u<<1|1]+1))%mod;
		mul[u<<1]=(mul[u<<1]*mul[u])%mod;
		mul[u<<1|1]=(mul[u<<1|1]*mul[u])%mod;
		add[u<<1]=(add[u<<1]*mul[u]+add[u])%mod;
		add[u<<1|1]=(add[u<<1|1]*mul[u]+add[u])%mod;
        add[u]=0, mul[u]=1;
	}
	void build(int u, int l, int r)
	{
		L[u]=l, R[u]=r, add[u]=0, mul[u]=1;
		if(l==r)
		{
			sum[u]=a[l]%mod;
			return;
		}
		int mid=(l+r)>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
		pushup(u);
	}
	void modify_add(int u, int l, int r, int v)
	{
		if(l<=L[u] && r>=R[u])
		{
			add[u]=(add[u]+v)%mod;
			sum[u]=(sum[u]+v*(R[u]-L[u]+1))%mod;
			return;
		}
		pushdown(u);
		int mid=(L[u]+R[u])>>1;
		if(l<=mid) modify_add(u<<1, l, r, v);
		if(r>mid) modify_add(u<<1|1, l, r, v);
		pushup(u);
	}
	void modify_mul(int u, int l, int r, int v)
	{
		if(l<=L[u] && r>=R[u])
		{
            add[u]=(add[u]*v)%mod;
			mul[u]=(mul[u]*v)%mod;
			sum[u]=(sum[u]*v)%mod;
			return;
		}
		pushdown(u);
		int mid=(L[u]+R[u])>>1;
		if(l<=mid) modify_mul(u<<1, l, r, v);
		if(r>mid) modify_mul(u<<1|1, l, r, v);
		pushup(u);
	}
	ll query(int u, int l, int r)
	{
		if(l<=L[u] && r>=R[u]) return sum[u];
        pushdown(u);
        int mid=(L[u]+R[u])>>1; ll res=0;
        if(l<=mid) res=(res+query(u<<1, l, r))%mod;
        if(r>mid) res=(res+query(u<<1|1, l, r))%mod;
        return res;
	}
} sgt;

signed main()
{
	setIO();
	int n, q, _; cin>>n>>q>>_;
    for(int i=1; i<=n; i++) cin>>a[i];
    sgt.build(1, 1, n);
    while(q--)
    {
        int opt, l, r; cin>>opt>>l>>r;
        if(opt==1)
        {
            int v; cin>>v;
            sgt.modify_mul(1, l, r, v);
        }
        else if(opt==2)
        {
            int v; cin>>v;
            sgt.modify_add(1, l, r, v);
        }
        else
        {
            cout<<sgt.query(1, l, r)<<endl;
        }
    }
	return 0;
}