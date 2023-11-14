// Problem: P2709 小B的询问
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2709
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

const int N=50010;

int n, m, k, T;
int a[N], q[N], cnt[N], ans[N];
int res;

struct Query
{
	int l, r, id;
	bool operator<(const Query &T)const
	{ return q[l]==q[T.l] ? r<T.r : q[l]<q[T.l]; }
}Q[N];

inline void add(int x)
{
	res+=(2*cnt[a[x]]+1), cnt[a[x]]++;
}

inline void del(int x)
{
	res-=(2*cnt[a[x]]-1), cnt[a[x]]--;	
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, k=int_rd;
	T=sqrt(n);
	for(int i=1; i<=n; i++) a[i]=int_rd, q[i]=(i-1)/T+1;
	for(int i=1; i<=m; i++) Q[i].l=int_rd, Q[i].r=int_rd, Q[i].id=i;
	sort(Q+1, Q+m+1);
	int l=1, r=0;
	for(int i=1; i<=m; i++)
	{
		while(l>Q[i].l) add(--l);
		while(r<Q[i].r) add(++r);
		while(l<Q[i].l) del(l++);
		while(r>Q[i].r) del(r--);
		ans[Q[i].id]=res;
	}
	for(int i=1; i<=m; i++)
		cout<<ans[i]<<endl;
	return 0;
}