// Problem: P4281 [AHOI2008] 紧急集合 / 聚会
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4281
// Memory Limit: 125 MB
// Time Limit: 1000 ms

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

const int N=500010;
int n, q;
int fa[N][31], dep[N];
vector<int> g[N];

void dfs(int u, int pre)
{
	fa[u][0]=pre;
	dep[u]=dep[pre]+1;
	for(int k=1; k<=30; k++)
		fa[u][k]=fa[fa[u][k-1]][k-1];
	for(auto v: g[u])
	{
		if(v==pre) continue;
		dfs(v, u);
	}
}
int lca(int a, int b)
{
	if(dep[a]<dep[b]) swap(a, b);
	for(int k=30; k>=0; k--)
		if(dep[fa[a][k]]>=dep[b])
			a=fa[a][k];
	if(a==b) return a;
	for(int k=30; k>=0; k--)
	{
		if(fa[a][k]!=fa[b][k])
		{
			a=fa[a][k];
			b=fa[b][k];
		}
	}
	return fa[a][0];
}

int main()
{
	n=int_rd, q=int_rd;
	for(int i=1; i<n; i++)
	{
		int u=int_rd, v=int_rd;
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	dfs(1, 0);
	while(q--)
	{
		int a=int_rd, b=int_rd, c=int_rd;
		int lca1=lca(a, b), lca2=lca(a, c), lca3=lca(b, c);
		int ans;
		if(lca1==lca2) ans=lca3;
		else if(lca1==lca3) ans=lca2;
		else ans=lca1;
		cout<<ans<<' '<<dep[a]+dep[b]+dep[c]-dep[lca1]-dep[lca2]-dep[lca3]<<endl;
	}
	return 0;
}