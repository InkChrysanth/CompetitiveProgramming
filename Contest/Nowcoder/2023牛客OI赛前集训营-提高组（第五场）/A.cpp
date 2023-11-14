// Problem: 矩阵交换
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65196/A
// Memory Limit: 524288 KB
// Time Limit: 2000 ms

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

const int N=110;

int n, m;

struct Node
{
	int a[N];
	bool operator<(const Node &T)const
	{
		for(int i=1; i<=n; i++)
			if(a[i]!=T.a[i])
				return a[i]<T.a[i];
		return false;
	}
}g[N];

bool check()
{
	for(int i=1; i<n; i++)
		for(int j=1; j<=m; j++)
			if(g[i].a[j]>g[i+1].a[j])
				return false;
	return true;
}

void kumiko()
{
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			g[i].a[j]=int_rd;
	sort(g+1, g+n+1);
	if(check()) puts("YES");
	else puts("NO");
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) kumiko();
	return 0;
}