// Problem: P3919 【模板】可持久化线段树 1（可持久化数组）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3919
// Memory Limit: 1 GB
// Time Limit: 1500 ms

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

const int N=1000010, M=(N<<5)+10;

struct Node
{
	int l, r;
	int val;
}tr[M];

int n, m, cnt;
int a[N], rt[M];

void build(int &u, int l, int r)
{
	u=++cnt;
	if(l==r)
	{
		tr[u].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(tr[u].l, l, mid);
	build(tr[u].r, mid+1, r);
}

void ins(int &u, int ver, int l, int r, int k, int x)
{
	u=++cnt; tr[u]=tr[ver];
	if(l==r)
	{
		tr[u].val=x;
		return;	
	}
	int mid=(l+r)>>1;
	if(k<=mid) ins(tr[u].l, tr[ver].l, l, mid, k, x);
	else ins(tr[u].r, tr[ver].r, mid+1, r, k, x);
}

int query(int u, int l, int r, int k)
{
	if(l==r) return tr[u].val;
	int mid=(l+r)>>1;
	if(k<=mid) return query(tr[u].l, l, mid, k);
	else return query(tr[u].r, mid+1, r, k);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++) a[i]=int_rd;
	build(rt[0], 1, n);
	for(int i=1, ver, op, k, x; i<=m; i++)
	{
		ver=int_rd, op=int_rd, k=int_rd;
		if(op==1) x=int_rd, ins(rt[i], rt[ver], 1, n, k, x);
		if(op==2) cout<<query(rt[ver], 1, n, k)<<endl, rt[i]=rt[ver];
	}
	return 0;
}