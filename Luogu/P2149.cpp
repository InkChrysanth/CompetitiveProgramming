// Problem: P2149 [SDOI2009] Elaxia的路线
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2149
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define y0 y114514
#define y1 y1919810
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); ll f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}

const int N=1510, M=300010;

int n, m;
int x1, y1, x2, y2;
vector<pii> g[N], gg[N], ggg[N];
int dist[4][N], d[N], len[N];
bool vis[N];

void dijkstra(int st, int id)
{
	memset(vis, false, sizeof vis);
	memset(dist[id], inf, sizeof dist[id]);
	priority_queue<pii, vector<pii>, greater<pii> > heap;
	heap.push(mp(dist[id][st]=0, st));
	while(heap.size())
	{
		auto u=heap.top().second; heap.pop();
		if(vis[u]) continue; vis[u]=true;
		for(auto [v, w]: g[u])
			if(dist[id][v]>dist[id][u]+w)
				heap.push(mp(dist[id][v]=dist[id][u]+w, v));
	}
}

void topsort(vector<pii> graph[N])
{
	memset(len, 0, sizeof len);
	memset(vis, false, sizeof vis);
	queue<int> q;
	For(i, 1, n) if(!d[i]) q.push(i);
	while(q.size())
	{
		int u=q.front(); q.pop();
		for(auto [v, w]: graph[u])
		{
			d[v]--;
			len[v]=max(len[v], len[u]+w);
			if(!d[v]) q.push(v);
		}
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m, x1, y1, x2, y2);
	For(i, 1, m)
	{
		int u, v, w; rd(u, v, w);
		g[u].eb(mp(v, w)); g[v].eb(mp(u, w));
	}
	dijkstra(x1, 0);
	dijkstra(y1, 1);
	dijkstra(x2, 2);
	dijkstra(y2, 3);
	int ans=0;
	For(u, 1, n)
		for(auto [v, w]: g[u])
			if(dist[0][u]+w+dist[1][v]==dist[0][y1] &&
			dist[2][u]+w+dist[3][v]==dist[2][y2])
				gg[u].eb(mp(v, w)), d[v]++;
	topsort(gg);
	For(i, 1, n) ans=max(ans, len[i]);
	memset(d, 0, sizeof d);
	For(u, 1, n)
		for(auto [v, w]: g[u])
			if(dist[0][u]+w+dist[1][v]==dist[0][y1] &&
			dist[3][u]+w+dist[2][v]==dist[2][y2])
				ggg[u].eb(mp(v, w)), d[v]++;
	topsort(ggg);
	For(i, 1, n) ans=max(ans, len[i]);
	cout<<ans<<endl;
	return 0;
}