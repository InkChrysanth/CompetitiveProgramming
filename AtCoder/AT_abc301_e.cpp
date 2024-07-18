#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
constexpr int N=310, M=20;

int dx[5]={0, -1, 1, 0, 0};
int dy[5]={0, 0, 0, -1, 1};

int n, m, step, tot;
map<pii, int> hs;
pii pts[M];
pii st, ed;
bool g[N][N];
int d[M][M];
int dist[N][N];
bool vis[N][N];
int f[M][1<<M];

bool check(int x, int y)
{
    return x>0 && x<=n && y>0 && y<=m && !g[x][y];
}

void bfs(int u)
{
    queue<pii> q;
    memset(vis, 0, sizeof vis);
    memset(dist, 0, sizeof dist);
    q.push(pts[u]);
    vis[pts[u].fi][pts[u].se]=1;
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        for(int i=1; i<=4; i++)
        {
            int x=t.fi+dx[i], y=t.se+dy[i];
            if(vis[x][y] || !check(x, y)) continue;
            vis[x][y]=1;
            dist[x][y]=dist[t.fi][t.se]+1;
            // cerr<<"x:"<<x<<" y:"<<y<<endl;
            // debug(dist[x][y]);
            // debug(hs[mp(x, y)]);
            if(~hs[mp(x, y)]) d[u][hs[mp(x, y)]]=dist[x][y];
            q.push(mp(x, y));
        }
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>step;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char c;
            cin>>c;
            hs[mp(i, j)]=-1;
            if(c=='S') st=mp(i, j);
            if(c=='G') ed=mp(i, j);
            if(c=='o') hs[mp(i, j)]=++tot, pts[tot]=mp(i, j);
            g[i][j]=(c=='#');
        }
    }
    memset(d, 0x3f, sizeof d);
    hs[st]=0; pts[0]=st;
    hs[ed]=++tot; pts[tot]=ed;
    for(int i=0; i<=tot; i++) bfs(i);
    for(int st=0; st<(1<<(tot+1)); st++)
        for(int i=0; i<=tot; i++)
            f[i][st]=inf;
    f[0][1]=0;
    for(int st=0; st<(1<<(tot+1)); st++)
    {
        for(int i=0; i<=tot; i++)
        {
            if(f[i][st]>step) continue;
            for(int k=0; k<=tot; k++)
            {
                cmin(f[k][st|(1<<k)], f[i][st]+d[i][k]);
            }
        }
    }
    int ans=0;
    for(int i=0; i<(1<<(tot+1)); i++)
    {
        if(f[tot][i]>step) continue;
        cmax(ans, __builtin_popcount(i));
    }
    cout<<((ans==0)?-1:ans-2)<<endl;
    return 0;
}
