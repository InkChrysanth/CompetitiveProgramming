// Problem: P3387 【模板】缩点
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3387
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

struct Node
{
	int u, v, ne;
}e[N];

int n, m, ans=0;
int h[N], idx;
int p[N], w[N], c[N], d[N], f[N];
int dfn[N];

void add(int u, int v)
{
	e[++idx].u=u, e[idx].v=v, e[idx].ne=h[u], h[u]=idx; 
}

int find(int x)
{
	if(x==p[x]) return p[x];
	return p[x]=find(p[x]);
}

void dfs(int u)
{
	for(int i=h[u]; ~i; i=e[i].ne)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			dfn[v]=dfn[u]+1;
			dfs(v);
		}
		int fu=find(u), fv=find(v);
		if(dfn[fv]>0)
		{
			if(dfn[fu]<dfn[fv]) p[fv]=fu;
			else p[fu]=fv;
		}
	}
	dfn[u]=-1;
}

void topsort()
{
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(p[i]==i && !d[i])
			q.push(i), f[i]=c[i];
	while(q.size())
	{
		auto u=q.front(); q.pop();
		for(int i=h[u]; ~i; i=e[i].ne)
		{
			int v=e[i].v;
			f[v]=max(f[v], f[u]+c[v]);
			if(--d[v]==0) q.push(v);
		}
		ans=max(ans, f[u]);
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	memset(h, -1, sizeof h);
	n=int_rd, m=int_rd;
	for(int i=1; i<=n; i++) 
		p[i]=i, w[i]=int_rd;
	for(int i=1; i<=m; i++)
	{
		int u=int_rd, v=int_rd;
		add(u, v);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) dfn[i]=1, dfs(i);
	for(int i=1; i<=n; i++)
		c[find(i)]+=w[i];
	idx=0; memset(h, -1, sizeof h);
	for(int i=1; i<=m; i++)
	{
		int u=p[e[i].u], v=p[e[i].v];
		if(u!=v) add(u, v), d[v]++;
	}
	topsort();
	cout<<ans<<endl;
	return 0;
}