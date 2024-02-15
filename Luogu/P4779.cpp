// Problem: P4779 【模板】单源最短路径（标准版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4779
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=100010, M=200010;
int n, m, st;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool vis[N];
void add(int a, int b, int c)
{
	e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	memset(vis, false, sizeof vis);
	__gnu_pbds::priority_queue<pii, greater<pii>> heap;
	dist[st]=0;
	heap.push({0, st});
	while(heap.size())
	{
		auto t=heap.top(); heap.pop();
        if(vis[t.second]) continue;
		vis[t.second]=true;
		for(int i=h[t.second]; ~i; i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t.second]+w[i])
			{
				dist[j]=dist[t.second]+w[i];
				if(!vis[j]) heap.push({dist[j], j});
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>st;
	for(int i=1; i<=m; i++)
	{
		int a, b, c; cin>>a>>b>>c;
		add(a, b, c);
	}
	dijkstra();
	for(int i=1; i<=n; i++)
		cout<<dist[i]<<' ';
	return 0;
}