// Problem: P4513 小白逛公园
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4513
// Memory Limit: 128 MB
// Time Limit: 1000 ms

// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline ll read()
{
	ll a=0; int f=0; char p=getchar();
	while(!isdigit(p)){f|=p=='-'; p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48); p=getchar();}
	return f?-a:a;
}

const int N=500010;
int n, m;
int a[N];

struct Node
{
	int l, r;
	int sum, lmx, rmx, ans;
}tr[N<<2];

void pushup(int u)
{
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
	tr[u].lmx=max(tr[u<<1].lmx, tr[u<<1].sum+tr[u<<1|1].lmx);
	tr[u].rmx=max(tr[u<<1|1].rmx, tr[u<<1|1].sum+tr[u<<1].rmx);
	tr[u].ans=max({tr[u<<1].ans, tr[u<<1|1].ans, tr[u<<1].rmx+tr[u<<1|1].lmx});
}

void build(int u, int l, int r)
{
	if(l==r)
	{
		tr[u]={l,r,a[l],a[l],a[l],a[l]};
		return;
	}
	else
	{
		tr[u]={l,r,0,0,0,0};
		int mid=(l+r)>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
		pushup(u);
	}
}

void modify(int u, int k, int x)
{
	if(tr[u].l==tr[u].r)
	{
		tr[u]={tr[u].l,tr[u].r,x,x,x,x};
		return;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	if(k<=mid) modify(u<<1, k, x);
	else modify(u<<1|1, k, x);
	pushup(u);
}

Node query(int u, int l, int r)
{
	if(l<=tr[u].l && r>=tr[u].r) return tr[u];	
	int mid=(tr[u].l+tr[u].r)>>1;
	if(r<=mid) return query(u<<1, l, r);
	else if(l>mid) return query(u<<1|1, l, r);
	else
	{
		Node x=query(u<<1, l, r), y=query(u<<1|1, l, r);
		Node res;
		res.lmx=max(x.lmx, x.sum+y.lmx);
		res.rmx=max(y.rmx, y.sum+x.rmx);
		res.ans=max({x.ans, y.ans, x.rmx+y.lmx});
		return res;
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	build(1, 1, n);
	while(m--)
	{
		int op=int_rd, x=int_rd, y=int_rd;
		if(op==1)
		{
			if(x>y) swap(x, y);
			cout<<query(1, x, y).ans<<endl;
		}
		if(op==2) modify(1, x, y);
	}
	return 0;
}