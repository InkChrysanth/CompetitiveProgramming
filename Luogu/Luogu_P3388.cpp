// Problem: P3388 【模板】割点（割顶）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3388
// Memory Limit: 125 MB
// Time Limit: 1000 ms

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
int n, m, R;
int dfn[N], low[N], dn, cnt;
bool flag[N];
vector<int> g[N];
void dfs(int u)
{
	dfn[u]=low[u]=++dn;
	int son=0;
	for(auto v: g[u])
	{
		if(!dfn[v])
		{
			son++, dfs(v), low[u]=min(low[u], low[v]);
			if(low[v]>=dfn[u] && u!=R) cnt+=!flag[u], flag[u]=true;
		}
		else low[u]=min(low[u], dfn[v]);
	}
	if(son>=2 && u==R) cnt+=!flag[u], flag[u]=true;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd;
	for(int i=1; i<=m; i++)
	{
		int u=int_rd, v=int_rd;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) R=i, dfs(i);
	cout<<cnt<<endl;
	for(int i=1; i<=n; i++)
		if(flag[i]) cout<<i<<' ';
	return 0;
}