// Problem: Complete The Graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF715B
// Memory Limit: 250 MB
// Time Limit: 4000 ms

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

const int N=1010, M=10010;
const ll inf=1e18;
int n, m;
int L, st, ed;
int u[M], v[M], w[M];
vector<int> sp;
vector<pii> g[N];
ll dist[N];
bool vis[N];

void dijkstra()
{
	memset(vis, false, sizeof vis);
	fill(dist, dist+N-1, inf);
	priority_queue<pii, vector<pii>, greater<pii> > heap;
	heap.push(mp(0, st)); dist[st]=0;
	while(heap.size())
	{
		auto u=heap.top().second; heap.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto [v, w]: g[u])
			if(dist[v]>dist[u]+w)
				dist[v]=dist[u]+w, heap.push(mp(dist[v], v));
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	n=int_rd, m=int_rd, L=int_rd, st=int_rd, ed=int_rd;
	for(int i=1; i<=m; i++)
	{
		u[i]=int_rd, v[i]=int_rd, w[i]=int_rd;
		if(!w[i]){sp.emplace_back(i); continue;}
		g[u[i]].emplace_back(mp(v[i], w[i]));
		g[v[i]].emplace_back(mp(u[i], w[i]));
	}
	dijkstra();
	// cout<<dist[ed]<<endl;
	if(dist[ed]<L){cout<<"NO"<<endl; return 0;}
	else if(dist[ed]==L)
	{
		cout<<"YES"<<endl;
		for(int i=1; i<=m; i++)
			cout<<u[i]<<' '<<v[i]<<' '<<(w[i]==0?inf:w[i])<<endl;
		return 0;
	}
	else
	{
		for(auto i: sp)
		{
			g[u[i]].emplace_back(mp(v[i], 1));
			g[v[i]].emplace_back(mp(u[i], 1));
			dijkstra();
			if(dist[ed]<=L)
			{
				cout<<"YES"<<endl;
				for(int j=1; j<=m; j++)
				{
					if(!w[j])
					{
						if(j<i) cout<<u[j]<<' '<<v[j]<<' '<<1<<endl;
						else if(j==i) cout<<u[j]<<' '<<v[j]<<' '<<L-dist[ed]+1<<endl;
						else cout<<u[j]<<' '<<v[j]<<' '<<inf<<endl;
					}
					else cout<<u[j]<<' '<<v[j]<<' '<<w[j]<<endl;
				}
				return 0;
			}
		}
		cout<<"NO"<<endl;
	}
	return 0;
}