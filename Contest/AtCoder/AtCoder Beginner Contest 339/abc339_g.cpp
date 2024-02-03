// Problem: G - Smaller Sum
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024 (AtCoder Beginner Contest 339)
// URL: https://atcoder.jp/contests/abc339/tasks/abc339_g
// Memory Limit: 1024 MB
// Time Limit: 3500 ms

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

const int N=200010, M=1010;
ll n, m, T, tot, lastans;
ll a[N];
ll q[N], l[M], r[M];
ll b[N], pre[N];

void init()
{
	while(++tot)
	{
		l[tot]=r[tot-1]+1;
		r[tot]=min(T*tot, n);
		for(int i=l[tot]; i<=r[tot]; i++)
			q[i]=tot, b[i]=a[i];
		sort(b+l[tot], b+r[tot]+1);
		for(int i=l[tot]; i<=r[tot]; i++)
			pre[i]=(i==l[tot] ? 0ll : pre[i-1])+b[i];
		if(r[tot]==n) break;
	}
}

ll query(ll x, ll y, ll c)
{
	ll ans=0;
	if(q[x]==q[y])
	{
		for(int i=x; i<=y; i++)
			if(a[i]<=c)
				ans+=a[i];
	}
	else
	{
		for(int i=x; i<=r[q[x]]; i++)
			if(a[i]<=c)
				ans+=a[i];
		for(int i=l[q[y]]; i<=y; i++)
			if(a[i]<=c)
				ans+=a[i];
		for(int i=q[x]+1; i<q[y]; i++)
		{
			ll pos=upper_bound(b+l[i], b+r[i]+1, c)-b-1;
			ans+=(pos==l[i]-1 ? 0 : pre[pos]);
		}
	}
	return ans;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=ll_rd, T=sqrt(n)*2; T=min(T, n);
	for(int i=1; i<=n; i++) a[i]=ll_rd;
	init();
	m=ll_rd;
	while(m--)
	{
		ll x=ll_rd, y=ll_rd, c=ll_rd;
		x^=lastans, y^=lastans, c^=lastans;
		cout<<(lastans=query(x, y, c))<<endl;
	}
	return 0;
}