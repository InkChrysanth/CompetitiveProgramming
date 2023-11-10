// Problem: P3946 ことりのおやつ（小鸟的点心）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3946
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/extc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N=100010, M=1000010, INF=0x3f3f3f3f;
int n, m, st, ed, g, q;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
pii len[N];
bool vis[N];
void add(int a, int b, int c)
{
	e[idx]=b, w[idx]=c, ne[idx]=h[a], h[a]=idx++;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
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
			if(dist[j]>dist[t.second]+w[i] && (len[j].first+(dist[t.second]+w[i])*q<=len[j].second || j==ed))
			{
				dist[j]=dist[t.second]+w[i];
				if(!vis[j]) heap.push({dist[j], j});
			}
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>st>>ed>>g>>q;
	for(int i=1; i<=n; i++)
		cin>>len[i].first>>len[i].second;
	for(int i=1; i<=m; i++)
	{
		int a, b, c; cin>>a>>b>>c;
		add(a, b, c), add(b, a, c);
	}
	dijkstra();
	if(dist[ed]>g) puts("wtnap wa kotori no oyatsu desu!");
	else cout<<dist[ed]<<endl;
	return 0;
}