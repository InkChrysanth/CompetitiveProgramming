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
constexpr int N=50010;

int n, m;
int init[N], dep[N], fa[N][30];
vector<pii> g[N];
ll dist[N][30];
bool sta[N], mark[N];
pli h[N]; int h_tot;
ll tim[N]; int tot;
ll re[N]; int _tot;

void bfs()
{
    queue<int> q;
    q.push(1); dep[1]=1;
    while(q.size())
    {
        int u=q.front(); q.pop();
        each(t, g[u])
        {
            int v=t.fi, w=t.se;
            if(dep[v]) continue;
            fa[v][0]=u; dep[v]=dep[u]+1;
            dist[v][0]=w;
            for(int k=1; k<30; k++)
            {
                fa[v][k]=fa[fa[v][k-1]][k-1];
                dist[v][k]=dist[fa[v][k-1]][k-1]+dist[v][k-1];
            }
            q.push(v);
        }
    }
}

bool dfs(int u)// Is this path stationed?
{
    if(sta[u]) return true;
    if(g[u].size()==1) return false;
    each(t, g[u])
    {
        int v=t.fi;
        if(dep[v]<dep[u]) continue;
        if(!dfs(v)) return false;
    }
    return true;
}

bool check(ll mid)
{
    memset(sta, false, sizeof sta);
    memset(mark, false, sizeof mark);
    h_tot=tot=_tot=0;
    for(int i=1; i<=m; i++)
    {
        int p=init[i]; ll cost=0;
        for(int j=29; j>=0; j--)
        {
            if(fa[p][j]>1 && cost+dist[p][j]<=mid)
            {
                cost+=dist[p][j];
                p=fa[p][j];
            }
        }
        if(fa[p][0]==1 && cost+dist[p][0]<=mid)
            h[++h_tot]=mp(mid-cost-dist[p][0], p);
        else sta[p]=true;
    }
    each(t, g[1]) if(!dfs(t.fi)) mark[t.fi]=true;
    sort(h+1, h+h_tot+1);
    for(int i=1; i<=h_tot; i++)
    {
        if(mark[h[i].se] && h[i].fi<dist[h[i].se][0]) mark[h[i].se]=false;
        else tim[++tot]=h[i].fi;
    }
    each(t, g[1]) if(mark[t.fi]) re[++_tot]=dist[t.fi][0];
    if(tot<_tot) return false;
    sort(tim+1, tim+tot+1);
    sort(re+1, re+_tot+1);
    int l=1, r=1;
    while(l<=tot && r<=_tot)
    {
        if(tim[l]>=re[r]) l++, r++;
        else l++;
    }
    return r>_tot;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1, u, v, w; i<n; i++)
    {
        cin>>u>>v>>w;
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
    }
    bfs();
    cin>>m;
    for(int i=1; i<=m; i++) cin>>init[i];
    ll l=0, r=1e14, ans=r;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        // debug(mid);
        if(check(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<(ans==r ? -1 : ans)<<endl;
	return 0;
}
