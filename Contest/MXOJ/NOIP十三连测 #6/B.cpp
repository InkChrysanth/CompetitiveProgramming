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
constexpr int mod=1e9+7;
constexpr int N=100010;

int n, m;
vector<pii> g[N];
vector<int> ans[N];

struct Node
{
    int id, dist;
    int cnt;
    bool operator<(const Node &T)const
    { return dist>T.dist; }
};

void dijkstra()
{
    priority_queue<Node> heap;
    vector<int> dist(n+1, inf);
    vector<bool> vis(n+1, false);
    heap.push({1, dist[1]=0, 0});
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        int u=t.id, cnt=t.cnt;
        if(vis[u]) continue;
        vis[u]=true;
        each(t, g[t.id])
        {
            int v=t.fi, w=t.se;
            if(dist[v]>dist[u]+w)
            {
                ans[v].clear();
                ans[v].eb(cnt+1);
                heap.push({v, dist[v]=dist[u]+w, cnt+1});
            }
            else if(dist[v]==dist[u]+w) ans[v].eb(cnt+1);
        }
    }
}

signed main()
{
    Fre("bob");
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1, u, v, w; i<=m; i++)
    {
        cin>>u>>v>>w;
        g[u].eb(mp(v, w));
    }
    dijkstra();
    ll res=0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<ans[i].size(); j++)
            for(int k=j+1; k<ans[i].size(); k++)
                (res+=(1ll*ans[i][j]*ans[i][k]))%=mod;
    cout<<res<<endl;
	return 0;
}
