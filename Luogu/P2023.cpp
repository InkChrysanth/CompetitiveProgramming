// Problem: P2023 [AHOI2009] 维护序列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2023
// Memory Limit: 125 MB
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

const int N=100010;

struct Node
{
	int l, r;
	int sum, mul, add;
}tr[N*4];

int n, p, q;
int a[N];

void calc(Node &x, int mul, int add)
{
	x.sum=((1ll*x.sum*mul)%p+(1ll*(x.r-x.l+1)*add)%p)%p;
	x.mul=(1ll*x.mul*mul)%p;
	x.add=(1ll*x.add*mul+add)%p;
}

void pushup(int u)
{
	tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}

void pushdown(int u)
{
	calc(tr[u<<1], tr[u].mul, tr[u].add);
	calc(tr[u<<1|1], tr[u].mul, tr[u].add);
	tr[u].mul=1, tr[u].add=0;
}

void build(int u, int l, int r)
{
	if(l==r) tr[u]={l, r, a[l], 1, 0};
	else
	{
		tr[u]={l, r, 0, 1, 0};
		int mid=(l+r)>>1;
		build(u<<1, l, mid);
		build(u<<1|1, mid+1, r);
		pushup(u);
	}
}

void modify(int u, int l, int r, int mul, int add)
{
	if(l<=tr[u].l && r>=tr[u].r) calc(tr[u], mul, add);
	else
	{
		pushdown(u);
		int mid=(tr[u].l+tr[u].r)>>1;
		if(l<=mid) modify(u<<1, l, r, mul, add);
		if(r>mid) modify(u<<1|1, l, r, mul, add);
		pushup(u);
	}
}

int query(int u, int l, int r)
{
	if(l<=tr[u].l && r>=tr[u].r) return tr[u].sum;
	pushdown(u);
	int res=0;
	int mid=(tr[u].l+tr[u].r)>>1;
	if(l<=mid) res=(res+query(u<<1, l, r))%p;
	if(r>mid) res=(res+query(u<<1|1, l, r))%p;
	return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, p=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	build(1, 1, n);
	q=int_rd;
	while(q--)
	{
		int op=int_rd, l=int_rd, r=int_rd, c;
		if(op==1) c=int_rd, modify(1, l, r, c, 0);
		if(op==2) c=int_rd, modify(1, l, r, 1, c);
		if(op==3) cout<<query(1, l, r)<<endl;
	}
	return 0;
}