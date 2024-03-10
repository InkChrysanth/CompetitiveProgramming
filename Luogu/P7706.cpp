//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={1, 0, -1, 0, 1, -1, 1, -1};

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); ll f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}

const int N=500010;

struct Node
{
	int l, r;
	int mx, mn, lmx, rmx;
	int res;
}tr[N<<2];

int n, m;
int a[N], b[N];

void pushup(int u)
{
	tr[u].mx=max(tr[u<<1].mx, tr[u<<1|1].mx);
	tr[u].mn=min(tr[u<<1].mn, tr[u<<1|1].mn);
	tr[u].lmx=max({tr[u<<1].lmx, tr[u<<1|1].lmx, tr[u<<1].mx-tr[u<<1|1].mn});
	tr[u].rmx=max({tr[u<<1].rmx, tr[u<<1|1].rmx, tr[u<<1|1].mx-tr[u<<1].mn});
	tr[u].res=max({tr[u<<1].res, tr[u<<1|1].res, tr[u<<1].lmx+tr[u<<1|1].mx, tr[u<<1].mx+tr[u<<1|1].rmx});
}

void build(int u, int l, int r)
{
	tr[u].l=l, tr[u].r=r;
	if(l==r)
	{
		tr[u].mx=a[l], tr[u].mn=b[l];
		tr[u].lmx=tr[u].rmx=tr[u].res=-inf;
		return;	
	}
	int mid=(l+r)>>1;
	build(u<<1, l, mid);
	build(u<<1|1, mid+1, r);
	pushup(u);
}

void modify(int u, int k)
{
	if(tr[u].l==tr[u].r)
	{
		tr[u].mx=a[k], tr[u].mn=b[k];
		return;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	if(k<=mid) modify(u<<1, k);
	if(k>mid) modify(u<<1|1, k);
	pushup(u);
}

Node query(int u, int l, int r)
{
	if(l<=tr[u].l && tr[u].r<=r) return tr[u];
	int mid=(tr[u].l+tr[u].r)>>1;
	if(r<=mid) return query(u<<1, l, r);
	if(l>mid) return query(u<<1|1, l, r);
	Node ans, ls=query(u<<1, l, r), rs=query(u<<1|1, l, r);
	ans.mx=max(ls.mx, rs.mx), ans.mn=min(ls.mn, rs.mn);
	ans.lmx=max({ls.lmx, rs.lmx, ls.mx-rs.mn});
	ans.rmx=max({ls.rmx, rs.rmx, rs.mx-ls.mn});
	ans.res=max({ls.res, rs.res, ls.lmx+rs.mx, ls.mx+rs.rmx});
	return ans;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
	For(i, 1, n) rd(a[i]);
	For(i, 1, n) rd(b[i]);
	build(1, 1, n);
	while(m--)
	{
		int op, l, r; rd(op, l, r);
		if(op==1) a[l]=r, modify(1, l);
		if(op==2) b[l]=r, modify(1, l);
		if(op==3) cout<<query(1, l, r).res<<endl;
	}
	return 0;
}