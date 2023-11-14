// Problem: P4145 上帝造题的七分钟 2 / 花神游历各国
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4145
// Memory Limit: 125 MB
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

const int N=100010, M=320;
int n, m, T;
int a[N], q[N], sum[M], l[M], r[M];
bool vis[N];

void modify(int x, int y)
{
	if(q[x]==q[y])
	{
		if(vis[q[x]]) return;
		for(int i=x; i<=y; i++)
		{
			sum[q[x]]-=a[i];
			a[i]=sqrt(a[i]);
			sum[q[x]]+=a[i];
		}
		if(sum[q[x]]==r[q[x]]-l[q[x]]+1) vis[q[x]]=true;
	}
	else
	{
		for(int i=x; i<=r[q[x]]; i++)
		{
			sum[q[x]]-=a[i];
			a[i]=sqrt(a[i]);
			sum[q[x]]+=a[i];
		}
		for(int i=l[q[y]]; i<=y; i++)
		{
			sum[q[y]]-=a[i];
			a[i]=sqrt(a[i]);
			sum[q[y]]+=a[i];
		}
		for(int i=q[x]+1; i<q[y]; i++)
		{
			if(vis[i]) continue;
			for(int j=l[i]; j<=r[i]; j++)
			{
				sum[i]-=a[j];
				a[j]=sqrt(a[j]);
				sum[i]+=a[j];
			}
			if(sum[i]==r[i]-l[i]+1) vis[i]=true;
		}
	}
}

int query(int x, int y)
{
	int s=0;
	if(q[x]==q[y])
	{
		for(int i=x; i<=y; i++)
			s+=a[i];
	}
	else
	{
		for(int i=x; i<=r[q[x]]; i++)
			s+=a[i];
		for(int i=l[q[y]]; i<=y; i++)
			s+=a[i];
		for(int i=q[x]+1; i<q[y]; i++)
			s+=sum[i];
	}
	return s;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd; T=sqrt(n);
	for(int i=1; i<=n; i++)
	{
		a[i]=int_rd;
		q[i]=(i-1)/T+1;
		sum[q[i]]+=a[i];
		if(!l[q[i]]) l[q[i]]=i;
		r[q[i]]=i;
	}
	m=int_rd;
	while(m--)
	{
		int op=int_rd, x=int_rd, y=int_rd;
		if(x>y) swap(x, y);
		if(op==0) modify(x, y);
		else cout<<query(x, y)<<endl;
	}
	return 0;
}