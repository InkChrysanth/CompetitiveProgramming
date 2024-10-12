#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> g(n+1, vector<ll>(n+1, llinf));
    vector<pair<pii, ll>> dat(m+1);
    for(int i=1; i<=n; i++)
        g[i][i]=0;
    for(int i=1; i<=m; i++)
    {
        int u, v; ll w; cin>>u>>v>>w;
        dat[i]=mp(mp(u, v), w);
        g[u][v]=g[v][u]=w;
    }
    vector<pair<int, pii>> Q(q+1);
    for(int i=1; i<=q; i++)
    {
        int opt, u, v; cin>>opt>>u;
        if(opt==1) g[dat[u].fi.fi][dat[u].fi.se]=g[dat[u].fi.se][dat[u].fi.fi]=llinf;
        else cin>>v;
        Q[i]=mp(opt, mp(u, v));
    }
    for(int c=1; c<=n; c++)
        for(int a=1; a<=n; a++)
            for(int b=1; b<=n; b++)
                cmin(g[a][b], g[a][c]+g[c][b]);
    vector<ll> ans(q+1);
    for(int i=q; i>=1; i--)
    {
        if(Q[i].fi==1)
        {
            int k=Q[i].se.fi;
            g[dat[k].fi.fi][dat[k].fi.se]=g[dat[k].fi.se][dat[k].fi.fi]=min(g[dat[k].fi.fi][dat[k].fi.se], dat[k].se);
            for(int a=1; a<=n; a++)
                for(int b=1; b<=n; b++)
                    cmin(g[a][b], g[a][dat[k].fi.fi]+g[dat[k].fi.fi][b]);
            for(int a=1; a<=n; a++)
                for(int b=1; b<=n; b++)
                    cmin(g[a][b], g[a][dat[k].fi.se]+g[dat[k].fi.se][b]);
        }
        else ans[i]=g[Q[i].se.fi][Q[i].se.se];
    }
    for(int i=1; i<=q; i++)
        if(Q[i].fi==2)
            cout<<(ans[i]>=llinf ? -1 : ans[i])<<endl;
	return 0;
}
// graphs(floyd)