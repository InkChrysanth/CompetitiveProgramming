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
constexpr int mod=998244353;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    int m; cin>>m;
    vector<int> pos(m+1), val(m+1), opt(m+1);
    vector<vector<int>> g(m+1);
    vector<int> in(m+1, 0);
    for(int i=1; i<=m; i++)
    {
        cin>>opt[i];
        if(opt[i]==1) cin>>pos[i]>>val[i];
        else if(opt[i]==2) cin>>val[i];
        else
        {
            int c; cin>>c;
            while(c--)
            {
                int v; cin>>v;
                g[i].eb(v); in[v]++;
            }
        }
    }
    int t; cin>>t;
    while(t--)
    {
        int v; cin>>v;
        g[0].eb(v); in[v]++;
    }
    queue<int> q;
    for(int i=0; i<=m; i++)
        if(!in[i]) q.em(i);
    vector<int> lst;
    while(q.size())
    {
        int u=q.front(); q.pop();
        lst.eb(u);
        each(v, g[u]) if(--in[v]==0) q.em(v);
    }
    vector<ll> mul(m+1);
    for(auto it=lst.rbegin(); it!=lst.rend(); it++)
    {
        int u=*it;
        mul[u]=(opt[u]==2 ? val[u] : 1);
        each(v, g[u]) mul[u]=(mul[u]*mul[v])%mod;
    }
    for(int i=1; i<=n; i++) a[i]=(a[i]*mul[0])%mod;
    vector<ll> f(m+1); f[0]=1;
    each(u, lst)
    {
        ll s=1;
        for(auto it=g[u].rbegin(); it!=g[u].rend(); it++)
        {
            int v=*it;
            f[v]=(f[v]+s*f[u])%mod;
            s=s*mul[v]%mod;
        }
        if(opt[u]==1) a[pos[u]]=(a[pos[u]]+f[u]*val[u])%mod;
    }
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
	return 0;
}
