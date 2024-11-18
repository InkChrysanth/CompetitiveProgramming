#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")

#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=1010, K=6;
constexpr int dx[]={0, -1, 0, 1}, dy[]={1, 0, -1, 0};

int n, m, k;
pii S, T;
int g[N][N];
int dist[N][N][K];

struct Node
{
	int x, y, tm;
	Node(int x, int y, int tm): x(x), y(y), tm(tm){}
};

signed main()
{
	setIO();
	memset(dist, 0x3f, sizeof dist);
	cin>>n>>m>>k;
	cin>>S.fi>>S.se>>T.fi>>T.se;
	vector<vector<pii>> id(N);
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
	{
		cin>>g[i][j];
		id[g[i][j]].eb(mp(i, j));
	}
	dist[S.fi][S.se][0]=0;
	auto inbound=[&](int x, int y) -> bool
	{ return x>=1 && x<=n && y>=1 && y<=m; };
	deque<Node> q; q.push_back(Node(S.fi, S.se, 0));
	
	int ans=inf;
	while(q.size())
	{
		auto t=q.front(); q.pop_front();
		if(dist[t.x][t.y][t.tm]>=ans) continue;
		if(t.x==T.fi && t.y==T.se)
		{
			cmin(ans, dist[t.x][t.y][t.tm]);
			continue;
		}
		if(t.tm<k)
		{
			each(c, id[g[t.x][t.y]]) if(!(c.fi==t.x && c.se==t.y) && dist[c.fi][c.se][t.tm+1]>dist[t.x][t.y][t.tm])
				dist[c.fi][c.se][t.tm+1]=dist[t.x][t.y][t.tm], q.push_front(Node(c.fi, c.se, t.tm+1));
		}
		for(int i=0; i<4; i++)
		{
			int nx=t.x+dx[i], ny=t.y+dy[i];
			if(inbound(nx, ny) && dist[nx][ny][t.tm]>dist[t.x][t.y][t.tm]+1)
				dist[nx][ny][t.tm]=dist[t.x][t.y][t.tm]+1, q.push_back(Node(nx, ny, t.tm));
		}
	}
	cout<<ans<<endl;
	return 0;
}
// bfs and similar(deque)