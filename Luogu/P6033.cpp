// Problem: P6033 [NOIP2004 提高组] 合并果子 加强版
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6033
// Memory Limit: 512 MB
// Time Limit: 500000 ms

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

const int N=100010;
int n, cnt[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd;
	for(int i=1; i<=n; i++)
		cnt[int_rd]++;
	queue<ll> x, y;
	for(int i=1; i<=100000; i++)
		for(int j=1; j<=cnt[i]; j++)
			x.push(i);
	ll ans=0;
	for(int i=1; i<n; i++)
	{
		ll p1, p2;
		if(x.front()<y.front() && x.size() || !y.size())
			p1=x.front(), x.pop();
		else p1=y.front(), y.pop();
		if(x.front()<y.front() && x.size() || !y.size())
			p2=x.front(), x.pop();
		else p2=y.front(), y.pop();
		y.push(p1+p2); ans+=(p1+p2);
	}
	cout<<ans<<endl;
	return 0;
}