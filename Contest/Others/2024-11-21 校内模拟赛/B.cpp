//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int N=2010, M=200010;

int n, m;
vector<int> g[N];
pii E[M];
bitset<N> vis;
bool con1[N][N];
bool con2[N][N];
int col[N];

void dfs1(int u, int rt)
{
    con1[rt][u]=true;
    vis.set(u);
    each(v, g[u]) if(!vis[v])
        dfs1(v, rt);
}

void dfs2(int u, int c, bool k, int rt)
{
    if(k) con2[rt][u]=(col[u]!=c);
    else col[u]=c;
    vis.set(u);
    each(v, g[u]) if(!vis[v])
        dfs2(v, c, k, rt);
}

signed main()
{
	setIO();
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u, v; cin>>u>>v;
        E[i]=mp(u, v);
        g[u].eb(v);
    }
    for(int i=1; i<=n; i++)
        vis.reset(), dfs1(i, i);
    for(int i=1; i<=n; i++)
    {
        vis.reset(); vis.set(i);
        memset(col, 0, sizeof col);
        for(int j=0; j<(int)g[i].size(); j++) if(!vis[g[i][j]])
            dfs2(g[i][j], j+1, 0, i);
        vis.reset(), vis.set(i);
        for(int j=(int)g[i].size()-1; j>=0; j--) if(!vis[g[i][j]])
            dfs2(g[i][j], j+1, 1, i);
    }
    for(int i=1; i<=m; i++)
        cout<<(con1[E[i].se][E[i].fi]^con2[E[i].fi][E[i].se] ? "diff" : "same")<<endl;
	return 0;
}
// graphs, dfs and similar