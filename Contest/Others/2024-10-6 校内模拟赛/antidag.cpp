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

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w){}
};
signed main()
{
    Fre("antidag");
	cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<Edge> E;
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        E.eb(u, v, w);
    }
    auto check=[&](int x)
    {
        vector<vector<int>> g(n+1);
        vector<int> in(n+1, 0);
        each(e, E) if(e.w>x)
        {
            g[e.u].eb(e.v);
            in[e.v]++;
        }
        queue<int> q;
        for(int i=1; i<=n; i++) if(!in[i])
            q.em(i);
        int cnt=0;
        while(q.size())
        {
            int u=q.front(); q.pop();
            each(v, g[u]) if(--in[v]==0)
                q.em(v);
            cnt++;
        }
        return cnt==n;// not exist a cycle
    };
    int l=1, r=1000000000, ans=r;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
// binary search, graphs(topsort)