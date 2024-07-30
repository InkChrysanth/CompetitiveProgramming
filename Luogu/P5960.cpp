// Problem: P5960 【模板】差分约束
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5960
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=5010;

vector<pii> g[N];

int n, m;
int dist[N], cnt[N];
bool ins[N];

//xi-xj<=ck : j->i, w=ck 最短路
//			or
//xj-xi>=-ck :i->j, w=-ck 最长路
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1, a, b, c; i<=m; i++)
	{
		cin>>a>>b>>c;
		g[a].eb(mp(b, -c));
	}
	for(int i=1; i<=n; i++)
		g[0].eb(mp(i, 0));
	bool flag=0;
	fill(dist+1, dist+n+1, -inf);
	queue<int> q;
	q.push(0); ins[0]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		ins[u]=0;
		each(t, g[u])
		{
			int v=t.fi, w=t.se;
			if(dist[v]<dist[u]+w)
			{
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n+1)
				{
					flag=1;
					break;
				}
				if(!ins[v]) q.push(v), ins[v]=1;
			}
		}
	}
	if(flag) cout<<"NO"<<endl;
	else for(int i=1; i<=n; i++) cout<<dist[i]<<' ';
	return 0;
}
