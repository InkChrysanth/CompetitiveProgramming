// Problem: Beautiful Subarrays
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF665E
// Memory Limit: 500 MB
// Time Limit: 3000 ms

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
int n, k;
int son[N*31][2], sz[N*31], idx;

void insert(int x)
{
	int p=0;
	for(int i=31; i>=0; i--)
	{
		int u=x>>i&1;
		if(!son[p][u]) son[p][u]=++idx;
		p=son[p][u]; sz[p]++;
	}
}

int query(int x)
{
	int p=0, res=0;
	for(int i=31; i>=0; i--)
	{
		int u=x>>i&1;
		if(k>>i&1) p=son[p][u^1];
		else res+=sz[son[p][u^1]], p=son[p][u];
		if(p==0) break;
	}
	return res+sz[p];
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, k=int_rd;
	insert(0);
	ll ans=0, sum=0;
	for(int i=1; i<=n; i++)
	{
		int x=int_rd; sum^=x;
		ans+=1ll*query(sum);
		insert(sum);
	}
	cout<<ans<<endl;
	return 0;
}