// Problem: P3385 【模板】负环
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3385
// Memory Limit: 256 MB
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

const int N=2010, INF=INT_MAX;
int n, m;
int dist[N], cnt[N];
bool vis[N];

void spfa()
{
	vector<pii> g[N];
	n=int_rd, m=int_rd;
	for(int i=1; i<=m; i++)
	{
		int u=int_rd, v=int_rd, w=int_rd;
		g[u].emplace_back(mp(v, w));
		if(w>=0) g[v].emplace_back(mp(u, w));
	}
	queue<int> q;
	memset(cnt, 0, sizeof cnt);
	memset(vis, false, sizeof vis);
	fill(dist+1, dist+n+1, INF);
	dist[1]=0, vis[1]=false, q.push(1);
	while(q.size())
	{
		auto u=q.front(); q.pop();
		vis[u]=false;
		for(auto [v, w]: g[u])
		{
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n)
				{
					puts("YES");
					return;
				}
				if(!vis[v]) vis[v]=true, q.push(v);
			}
		}
	}
	puts("NO");
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T=int_rd;
	while(T--) spfa();
	return 0;
}