// Problem: P1608 路径统计
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1608
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=2010, INF=0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N], ans[N];
bool vis[N];

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1]=0, ans[1]=1;
	for(int i=1; i<=n; i++)
	{
		int t=-1;
		for(int j=1; j<=n; j++)
			if(!vis[j] && (t==-1 || dist[t]>dist[j])) t=j;
		vis[t]=true;
		for(int j=1; j<=n; j++)
		{
			if(dist[j]>dist[t]+g[t][j])
				dist[j]=dist[t]+g[t][j], ans[j]=ans[t];
			else if(dist[j]==dist[t]+g[t][j])
				ans[j]+=ans[t];
		}
	}
}

int main()
{
	memset(g, 0x3f, sizeof g);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int a, b, c; cin>>a>>b>>c;
		g[a][b]=min(g[a][b], c);
	}
	dijkstra();
	if(dist[n]==INF) puts("No answer");
	else cout<<dist[n]<<' '<<ans[n]<<endl;
	return 0;
}