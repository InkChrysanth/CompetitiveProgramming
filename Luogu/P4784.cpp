//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int N=100010, K=5;

int n, m, k;
vector<pii> g[N];
ll f[N][1<<K];
bool vis[N];
ll dist[N];
priority_queue<pli, vector<pli>, greater<pli>> heap;

void dijkstra(int st)
{
    memset(vis, false, sizeof vis);
    while(heap.size())
    {
        int u=heap.top().se;
        heap.pop();
        if(vis[u]) continue;
        vis[u]=true;
        each(t, g[u])
        {
            int v=t.fi, w=t.se;
            if(f[v][st]>f[u][st]+w)
                heap.push(mp(f[v][st]=f[u][st]+w, v));
        }
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k>>m;
    memset(f, 0x3f, sizeof f);
    for(int i=1; i<=k; i++)
    {
        int x; cin>>x;
        f[x][1<<(i-1)]=0;
    }
    for(int i=1, u, v, w; i<=m; i++)
    {
        cin>>u>>v>>w;
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    }
    for(int i=1; i<(1<<k); i++)
    {
        for(int k=1; k<=n; k++)
        {
            for(int j=i&(i-1); j; j=i&(j-1))
                cmin(f[k][i], f[k][j]+f[k][i^j]);
            if(f[k][i]<llinf) heap.push(mp(f[k][i], k));
        }
        dijkstra(i);
    }
    ll ans=llinf;
    for(int i=1; i<=n; i++) cmin(ans, f[i][(1<<k)-1]);
    cout<<ans<<endl;
	return 0;
}
