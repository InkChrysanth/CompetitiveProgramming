// Problem: The Child and Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF438D
// Memory Limit: 250 MB
// Time Limit: 4000 ms

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
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

const int N=100010, M=10010;
int n, m, T, tot;
int a[N], q[N];
int L[M], R[M], mx[M], sum[M];

void init()
{
	while(++tot)
	{
		L[tot]=R[tot-1]+1;
		R[tot]=min(T*tot, n);
		for(int i=L[tot]; i<=R[tot]; i++)
			q[i]=tot, sum[tot]+=a[i], mx[tot]=max(mx[tot], a[i]);
		if(R[tot]==n) break;
	}
}

void MOD(int l, int r, int p)
{
	for(int i=l; i<=r; i++) a[i]%=p;
	mx[q[l]]=sum[q[l]]=0;
	for(int i=L[q[l]]; i<=R[q[l]]; i++) sum[q[l]]+=a[i], mx[q[l]]=max(mx[q[l]], a[i]);
}

void change(int k, int x)
{
	sum[q[k]]-=a[k]; sum[q[k]]+=x; a[k]=x;
	mx[q[k]]=*max_element(a+L[q[k]], a+R[q[k]]+1);
}

void modify(int l, int r, int p)
{
	if(q[l]==q[r]) MOD(l, r, p);
	else
	{
		MOD(l, R[q[l]], p);
		MOD(L[q[r]], r, p);
		for(int i=q[l]+1; i<q[r]; i++)
			if(mx[i]>=p)
				MOD(L[i], R[i], p);
	}
}

int query(int l, int r)
{
	int res=0;
	if(q[l]==q[r]) for(int i=l; i<=r; i++) res+=a[i];
	else
	{
		for(int i=l; i<=R[q[l]]; i++)
			res+=a[i];
		for(int i=L[q[r]]; i<=r; i++)	
			res+=a[i];
		for(int i=q[l]+1; i<q[r]; i++)
			res+=sum[i];
	}
	return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd; T=min(40ll, n);
	for(int i=1; i<=n; i++)  a[i]=int_rd;
	init();
	while(m--)
	{
		int op=int_rd, l, r, k, x;
		if(op==1) l=int_rd, r=int_rd, cout<<query(l, r)<<endl;
		if(op==2) l=int_rd, r=int_rd, x=int_rd, modify(l, r, x);
		if(op==3) k=int_rd, x=int_rd, change(k, x);
	}
	return 0;
}