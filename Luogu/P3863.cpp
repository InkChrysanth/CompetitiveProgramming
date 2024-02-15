// Problem: P2801 教主的魔法
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2801
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

const int N=1000010, M=1010;
int n, m, T;
int a[N];
int q[N], l[M], r[M], sum[M];
vector<int> b[M];

void init(int u)
{
	b[u].clear();
	for(int i=l[u]; i<=min(r[u], n);i++)
        b[u].push_back(a[i]);
    sort(b[u].begin(), b[u].end());
}

void modify(int x, int y, int c)
{
	if(q[x]==q[y])
	{
		for(int i=x; i<=y; i++)
			a[i]+=c;
		init(q[x]);
	}
	else
	{
		for(int i=x; i<=r[q[x]]; i++)
			a[i]+=c;
		init(q[x]);
		for(int i=l[q[y]]; i<=y; i++)
			a[i]+=c;
		init(q[y]);
		for(int i=q[x]+1; i<q[y]; i++)
			sum[i]+=c;
	}
}

int query(int x, int y, int c)
{
	int ans=0;
	if(q[x]==q[y])
	{
		for(int i=x; i<=y; i++)
			if(a[i]+sum[q[x]]<c)
				ans++;
	}
	else
	{
		for(int i=x; i<=r[q[x]]; i++)
			if(a[i]+sum[q[x]]<c)
				ans++;
		for(int i=l[q[y]]; i<=y; i++)
			if(a[i]+sum[q[y]]<c)
				ans++;
		for(int i=q[x]+1; i<q[y]; i++)
			ans+=lower_bound(b[i].begin(), b[i].end(), c-sum[i])-b[i].begin();
	}
	return ans;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, T=sqrt(n);
	for(int i=1; i<=n; i++)
	{
		a[i]=int_rd;
		q[i]=(i-1)/T+1;
		if(!l[q[i]]) l[q[i]]=i;
		r[q[i]]=i;
		b[q[i]].push_back(a[i]);
	}
	for(int i=1; i<=q[n]; i++)
		sort(b[i].begin(), b[i].end());
	while(m--)
	{
		char op; cin>>op;
		int x=int_rd, y=int_rd, c=int_rd;
		if(op=='M') modify(x, y, c);
		if(op=='A') cout<<y-x+1-query(x, y, c)<<endl;
	}
	return 0;
}