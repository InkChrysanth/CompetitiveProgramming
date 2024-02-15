// Problem: P9836 种树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9836
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int_rd (int)read()
#define ll_rd read()
#define endl '\n'
#define mp make_pair
#define pbds __gnu_pbds
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

const int N=10010, MOD=998244353;

int n, m, ans=1;
int h[N], cnt[N];

void sum(int x, int k)
{
	pbds::priority_queue<int, greater<int>> heap;
	for(int i=1; i<=n; i++)
	{
		cnt[i]=1;
		while(h[i]%x==0)
		{
			cnt[i]++;
			h[i]/=x;
		}
		heap.push(cnt[i]);
	}
	while(k--)
	{
		int t=heap.top(); heap.pop();
		heap.push(t+1);
	}
	while(heap.size())
	{
		auto t=heap.top(); heap.pop();
		ans=ans*t%MOD;
	}
}

void kumiko()
{
	for(int i=2; i*i<=m; i++)
	{
		if(m%i==0)
		{
			int mcnt=0;
			while(m%i==0)
			{
				mcnt++;
				m/=i;
			}
			sum(i, mcnt);
		}
	}
	if(m!=1) sum(m, 1);
	for(int i=1; i<=n; i++)
	{
		for(int j=2; j*j<=h[i]; j++)
		{
			int cnt=1;
			while(h[i]%j==0) cnt++, h[i]/=j;
			ans=ans*cnt%MOD;
		}
		if(h[i]!=1) ans=ans*2%MOD;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(false); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++) h[i]=int_rd;
	kumiko();
	return 0;
}