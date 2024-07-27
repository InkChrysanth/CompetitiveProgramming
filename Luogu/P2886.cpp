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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=105;

int m, k, st, ed, tot;
map<int, int> hs;
int f[N][N<<1], g[N][N<<1];

struct Edge{ int u, v, w; }e[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>k>>m>>st>>ed;
	hs[st]=++tot;
	hs[ed]=++tot;
	st=hs[st];
	ed=hs[ed];
	for(int i=1, u, v, w; i<=m; i++)
	{
		cin>>w>>u>>v;
		if(!hs.count(u)) hs[u]=++tot;
		if(!hs.count(v)) hs[v]=++tot;
		// cerr<<hs[u]<<' '<<hs[v]<<endl;
		e[i]={hs[u], hs[v], w};
	}
	//fi,k: st->i 
	//gi,j: ed->i
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[st][0]=0;
	g[ed][0]=0;
	for(int i=1; i<=2*m; i++)	
		for(int j=1; j<=m; j++)
		{
			cmin(f[e[j].u][i], f[e[j].v][i-1]+e[j].w);
			cmin(f[e[j].v][i], f[e[j].u][i-1]+e[j].w);
			cmin(g[e[j].u][i], g[e[j].v][i-1]+e[j].w);
			cmin(g[e[j].v][i], g[e[j].u][i-1]+e[j].w);
		}
	auto calc=[&](int u, int val)
	{
		int res=inf;
		for(int p=0; p<=1; p++)
		{
			int mn=inf, dis=(k+p)%2;
			for(int j=m*2+p; j>=0; j-=2)
			{
				while(dis<m*2 && k-j-dis>=2)
				{
					dis+=2;
					mn+=2*val;
					cmin(mn, g[u][dis]);
				}
				if(mn==inf || f[u][j]==inf) continue;
				cmin(res, mn+f[u][j]+val*(k-j-dis));
			}
		}
		return res;
	};
	int ans=inf;
	for(int i=1; i<=m; i++)
		ans=min({ans, calc(e[i].u, e[i].w), calc(e[i].v, e[i].w)});
	cout<<ans<<endl;
	return 0;
}
