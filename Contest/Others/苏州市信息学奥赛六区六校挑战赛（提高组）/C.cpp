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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    
    vector<int> tar(n+1), w(n+1);
    vector<int> p(n+1);
    vector<vector<int>> g(n+1);
    
    for(int i=1; i<=n; i++) p[i]=i;
    function<int(int)> find=[&](int x)
    { return x==p[x] ? x : p[x]=find(p[x]); };

    for(int i=1; i<=n; i++)
    {
        cin>>w[i]>>tar[i];
        int fu=find(i), fv=find(tar[i]);
        if(fu!=fv)
        {
            p[fu]=fv;
            g[i].eb(tar[i]);
            g[tar[i]].eb(i);
        }
    }

    vector<array<ll, 2>> f(n+1);
    vector<bool> vis(n+1, 0);
    function<void(int, int)> dfs=[&](int u, int fa)
    {
        f[u]={0, w[u]};
        each(v, g[u])
        {
            if(v==fa) continue;
            dfs(v, u);
            f[u][0]+=max(f[v][0], f[v][1]);
            f[u][1]+=f[v][0];
        }
    };
    ll ans=0;
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=1; i<=n; i++)
    {
        int &u=i, &v=tar[i];
        int fu=find(u), fv=find(v);
        if(fu==fv)
        {
            ll mx=0;
            dfs(u, 0);
            cmax(mx, f[u][0]);
            dfs(v, 0);
            cmax(mx, f[v][0]);
            vis[u]=vis[v]=1;
            ans+=mx;
        }
        else p[fu]=fv;
    }

    vector<bool> st(n+1, 0);
    for(int i=1; i<=n; i++) if(vis[i]) st[find(i)]=1;
	for(int i=1; i<=n; i++)
    {
        if(!st[i] && find(i)==i)
        {
            dfs(i, 0);
            ans+=max(f[i][0], f[i][1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
