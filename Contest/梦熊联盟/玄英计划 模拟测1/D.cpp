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

int n, m, k, ans=0x3f3f3f3f;
int A[N], B[N];
int city[N];

int calc()
{
	int res=0;
	for(int i=1; i<=m; i++)
		if(city[i]&1) res++;
	return res;
}

void dfs(int u)
{
	if(u==n+1)
	{
		ans=min(ans, calc());
		return;
	}
	city[A[u]]++;
	dfs(u+1);
	city[A[u]]--;
	city[B[u]]++;
	dfs(u+1);
	city[B[u]]--;
}

signed main()
{
	freopen("profit.in", "r", stdin);
	freopen("profit.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, k=int_rd;
	if(n>20)
	{
		for(int i=1; i<=n; i++)
		{
			int a=int_rd, b=int_rd;
			city[a]++;
		}
		ans=calc();
	}
	else
	{
		for(int i=1; i<=n; i++)
			A[i]=int_rd, B[i]=int_rd;
		dfs(1);
	}
	cout<<k-ans<<endl;
	return 0;
}