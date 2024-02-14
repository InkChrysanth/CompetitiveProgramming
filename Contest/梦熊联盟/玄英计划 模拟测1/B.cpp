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

const int N=3010;
vector<int> g[N];
int mn=1e9, ans;
int dist[N], cnt[N];

void dijkstra(int st)
{
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	queue<int> q; q.push(st);
	dist[st]=0, cnt[st]=1;
	while(q.size())
	{
		auto u=q.front(); q.pop();
		for(auto v: g[u])
		{
			if(dist[u]==dist[v] || dist[u]+1==dist[v])
			{
				int len=dist[u]+dist[v]+1;
				ll res=cnt[u]*cnt[v];
				if(len<mn) mn=len, ans=res;
				else if(len==mn) ans+=res;
			}
			if(dist[u]+1<dist[v])
			{
				dist[v]=dist[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dist[u]+1==dist[v])
				cnt[v]+=cnt[u];
		}
	}
}

signed main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	int n=int_rd, m=int_rd;
	for(int i=1; i<=m; i++)
	{
		int u=int_rd, v=int_rd;
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	for(int i=1; i<=n; i++) dijkstra(i);
	if(mn&1) ans/=2;
	cout<<ans/mn<<endl;
	return 0;
}