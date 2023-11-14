// Problem: 学习LIS
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65196/C
// Memory Limit: 524288 KB
// Time Limit: 4000 ms

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

const int N=21, MOD=998244353;

int n, m, ans=0;
int a[N], b[N], f[N];

void dfs(int u)
{
	if(u==n+1){ans++; return;}
	for(int i=1; i<=m; i++)
	{
		b[u]=i; f[u]=1;
		for(int j=1; j<u; j++)
			if(b[j]<i)
				f[u]=max(f[u], f[j]+1);
		if(f[u]==a[u]) dfs(u+1);
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++)
		a[i]=int_rd;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}