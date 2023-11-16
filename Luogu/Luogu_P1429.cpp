// Problem: P1429 平面最近点对（加强版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1429
// Memory Limit: 256 MB
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

int n;
double ans=1e16;

struct Node
{
	int x, y, sum;
	bool operator<(const Node &T)const
	{
		return sum>T.sum;
	}
}a[N];

inline double calc(int i, int j)
{
	return sqrt((double)(a[i].x-a[j].x)*(a[i].x-a[j].x)+(double)(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd;
	for(int i=1; i<=n; i++)
		a[i].x=int_rd, a[i].y=int_rd, a[i].sum=(a[i].x+5555)*(a[i].y+5555);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=min(i+111, n); j++)
			ans=min(ans, calc(i, j));
	for(int i=1; i<=n; i++)
	    for(int j=n; j>=max(i+1, n-111); j--)
	        ans=min(ans, calc(i, j));
	printf("%.4lf\n", ans);
	return 0;
}