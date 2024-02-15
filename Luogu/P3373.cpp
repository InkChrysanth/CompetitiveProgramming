// Problem: P3373 【模板】线段树 2
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3373
// Memory Limit: 125 MB
// Time Limit: 1000 ms
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

int n, m, MOD;
int a[N];

struct Node
{
    int l, r;
    int sum, add, mul;
}tr[N*4];

void calc(Node &x, int add, int mul)
{
    x.sum=((1ll*x.sum*mul)+(1ll*(x.r-x.l+1)*add))%MOD;
    x.mul=(1ll*x.mul*mul)%MOD;
    x.add=(1ll*x.add*mul+add)%MOD;
}

void pushup(int u)
{
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%MOD;
}

void pushdown(int u)
{
    calc(tr[u<<1], tr[u].add, tr[u].mul);
    calc(tr[u<<1|1], tr[u].add, tr[u].mul);
    tr[u].add=0, tr[u].mul=1;
}

void build(int u, int l, int r)
{
    if(l==r) tr[u]={l, r, a[l], 0, 1};
    else
    {
        tr[u]={l, r, 0, 0, 1};
        int mid=l+r>>1;
        build(u<<1, l, mid);
        build(u<<1|1, mid+1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul)
{
    if(l<=tr[u].l && r>=tr[u].r) calc(tr[u], add, mul);
    else
    {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid) modify(u<<1, l, r, add, mul);
        if(r>mid) modify(u<<1|1, l, r, add, mul);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if(l<=tr[u].l && r>=tr[u].r) return tr[u].sum;
    pushdown(u);
    int sum=0;
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) sum=(sum+query(u<<1, l, r))%MOD;
    if(r>mid) sum=(sum+query(u<<1|1, l, r))%MOD;
    return sum;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd; m=int_rd; MOD=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	build(1, 1, n);
	for(int i=1; i<=m; i++)
	{
	    int op=int_rd, l=int_rd, r=int_rd, c;
	    if(op==1) c=int_rd, modify(1, l, r, 0, c);
	    if(op==2) c=int_rd, modify(1, l, r, c, 1);
	    if(op==3) cout<<query(1, l, r)<<endl;
	}
	return 0;
}