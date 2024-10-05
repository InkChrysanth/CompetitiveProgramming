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
constexpr int mod=1e9+7;
constexpr int N=100010;

int n, m, k;
vector<int> g[N];
int sz[N], tot;
bool vis[N];

void dfs(int u)
{
    vis[u]=1;
    sz[tot]++;
    each(v, g[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }
}

ll qmi(ll a, ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

signed main()
{
    Fre("head");
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1, u, v; i<=m; i++)
    {
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
            tot++, dfs(i);
    ll ans=1;
    for(int i=1; i<=tot; i++)
    {
        debug(sz[i]);
        if(sz[i]==1) continue;
        ans=ans*(sz[i]*(sz[i]-1)/2)%mod;
    }
    ans=qmi(ans, k);
    cout<<ans<<endl;
	return 0;
}
