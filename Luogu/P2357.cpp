// Problem: P2357 守墓人
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2357
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define int long long

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

const int N=200010;
int n, m, T;
int q[N], res[N], sum[N];
int luck[N];

void change(int l, int r, int k)
{
	for(int i=l; i<=min(q[l]*T, r); i++)
	{
		luck[i]+=k;
		res[q[i]]+=k;
	}
	if(q[l]!=q[r])
	{
		for(int i=(q[r]-1)*T+1; i<=r; i++)
		{
			luck[i]+=k;
			res[q[i]]+=k;
		}
	}
	for(int i=q[l]+1; i<q[r]; i++)
	{
		sum[i]+=k;
		res[i]+=k*T;
	}
}

int query(int l, int r)
{
	int s=0;
	for(int i=l; i<=min(q[l]*T, r); i++)
		s+=(luck[i]+sum[q[i]]);
	if(q[l]!=q[r])
		for (int i=(q[r]-1)*T+1; i<=r; i++)
			s+=(luck[i]+sum[q[i]]);
	for(int i=q[l]+1; i<q[r]; i++)
		s+=res[i];
	return s;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd; T=sqrt(n);
	for(int i=1; i<=n; i++)
	{
		q[i]=(i-1)/T+1;
		luck[i]=int_rd;
		res[q[i]]+=luck[i];
	}
	while(m--)
	{
		int op=int_rd;
		if(op==1)
		{
			int l=int_rd, r=int_rd, k=int_rd;
			change(l, r, k);
		}
		if(op==2)
		{
			int k=int_rd;
			change(1, 1, k);
		}
		if(op==3)
		{
			int k=int_rd;
			change(1, 1, -k);
		}
		if(op==4)
		{
			int l=int_rd, r=int_rd;
			cout<<query(l, r)<<endl;
		}
		if(op==5) cout<<luck[1]+sum[1]<<endl;
	}
	return 0;
}