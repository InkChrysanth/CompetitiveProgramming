// Problem: P7883 平面最近点对（加强加强版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7883
// Memory Limit: 512 MB
// Time Limit: 350000 ms

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

const int N=400010;

int n, ans=LLONG_MAX;

struct Node
{
	int x, y, sum;
	bool operator<(const Node &T)const
	{
		return sum>T.sum;
	}
}a[N];

inline int calc(int i, int j)
{
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd;
	for(int i=1; i<=n; i++)
		a[i].x=int_rd, a[i].y=int_rd, a[i].sum=(a[i].x+5555)*(a[i].y+5555);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=min(i+400, n); j++)
			ans=min(ans, calc(i, j));
	for(int i=1; i<=n; i++)
	    for(int j=n; j>=max(i+1, n-400); j--)
	        ans=min(ans, calc(i, j));
	cout<<ans<<endl;
	return 0;
}