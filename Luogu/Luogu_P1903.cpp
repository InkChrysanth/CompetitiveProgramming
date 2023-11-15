// Problem: P1903 [国家集训队] 数颜色 / 维护队列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1903
// Memory Limit: 512 MB
// Time Limit: 1500 ms

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

const int N=140010, W=1000010;

int ans=0;
int n, m, T;
int a[N], q[N], cnt[W], kumiko[N];

struct Query
{
	int l, r, id, tm;
	bool operator<(const Query &T)const
	{
		if(q[l]!=q[T.l]) return q[l]<q[T.l];
		if(q[r]!=q[T.r]) return r<T.r;
		return tm<T.tm;
	}
}Q[N]; int qcnt;

struct Modify
{
	int pos, val;
}M[N]; int mcnt;

inline void add(int x)
{
	if(++cnt[a[x]]==1) ans++;
}

inline void del(int x)
{
	if(--cnt[a[x]]==0) ans--;
}

inline void work(int cur, int i)
{
	if(M[cur].pos>=Q[i].l && M[cur].pos<=Q[i].r)
	{
		if(--cnt[a[M[cur].pos]]==0) ans--;
		if(++cnt[M[cur].val]==1) ans++;
	}
	swap(a[M[cur].pos], M[cur].val);
}
signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, T=pow(m, 0.666666);
	for(int i=1; i<=n; i++)
		a[i]=int_rd, q[i]=(i-1)/T+1;
	for(int i=1; i<=m; i++)
	{
		char op[2]; scanf("%s", op);
		if(op[0]=='Q')
		{
			qcnt++;
			Q[qcnt].l=int_rd; Q[qcnt].r=int_rd;
			Q[qcnt].tm=mcnt; Q[qcnt].id=qcnt;
		}
		if(op[0]=='R')
		{
			mcnt++;
			M[mcnt].pos=int_rd; M[mcnt].val=int_rd;
		}
	}
	sort(Q+1, Q+qcnt+1);
	int l=1, r=0, cur=0;
	for(int i=1; i<=qcnt; i++)
	{
		while(l>Q[i].l) add(--l);
		while(r<Q[i].r) add(++r);
		while(l<Q[i].l) del(l++);
		while(r>Q[i].r) del(r--);
		while(cur<Q[i].tm) work(++cur, i);
		while(cur>Q[i].tm) work(cur--, i);
		kumiko[Q[i].id]=ans;
	}
	for(int i=1; i<=qcnt; i++)
		cout<<kumiko[i]<<endl;
	return 0;
}