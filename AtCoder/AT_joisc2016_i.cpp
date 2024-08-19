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
constexpr int N=100010;

int n, tar[N], w[N];
vector<int> g[N];
int son[N];
int cycle[N], tot;
int st[N];
ll ans=0;

void find_cycle(int u)
{
    while(!st[u])
    {
        st[u]=1;
        u=tar[u];
    }
    tot=0;
    while(st[u]==1)
    {
        st[u]=2;
        cycle[++tot]=u;
        u=tar[u];
    }
}

void dfs(int u)
{
    if(!st[u]) st[u]=1;
    each(v, g[u])
    {
        if(st[v]==2) continue;
        dfs(v);
        if(w[son[u]]<w[v]) ans+=w[son[u]], son[u]=v;
        else ans+=w[v];
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>tar[i]>>w[i];
        g[tar[i]].eb(i);
    }
    for(int i=1; i<=n; i++)
    {
        if(st[i]) continue;
        find_cycle(i);
        if(tot==n) return cout<<0<<endl, 0;
        for(int i=1; i<=tot; i++)
            dfs(cycle[i]);
        ll res0=0, res1=llinf;
        for(int i=1; i<=tot; i++)
        {
            res1=min(min(res1, res0)+w[cycle[i]], res1+w[son[tar[cycle[i]]]]);
            res0=res0+w[son[tar[cycle[i]]]];
        }
        ans+=res1;
    }
    cout<<ans<<endl;
	return 0;
}
