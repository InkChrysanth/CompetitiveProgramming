//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
constexpr int N=100010;

int n;
ll a[N];
int b[N], c[N], f[N];
vector<int> g[N];

__int128 calc(int k, __int128 l, __int128 r)
{
    if(c[k]>=0) return (r-l+1)*b[k]+c[k]*(l+r)*(r-l+1)/2;
    __int128 t=(1-b[k])/c[k];
    if(t<l) return r-l+1;
    if(t>r) return (r-l+1)*b[k]+c[k]*(l+r)*(r-l+1)/2;
    return (t-l+1)*b[k]+c[k]*(l+t)*(t-l+1)/2+r-t;
}

void dfs(int u, int fa)
{
    each(v, g[u])
    {
        if(v!=fa)
        {
            dfs(v, u);
            cmin(f[u], f[v]-1);
        }
    }
    // debug(f[u]);
}

bool check(int t)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]>calc(i, 1, t)) return 0;
        int l=1, r=n;
        //binary search to find the latest start time
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[i]<=calc(i, mid, t)) l=mid+1, f[i]=mid;
            else r=mid-1;
        }
        //the No.1 node is always the first
        if(i==1) f[i]=1;
    }
    dfs(1, 0);
    vector<int> cnt(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        // debug(f[i]);
        if(f[i]<1) return 0;
        cnt[f[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        cnt[i]+=cnt[i-1];
        //exclude the invaild situation
        //i.e., the number of existent nodes < the nodes we need to find the sol
        if(cnt[i]>i) return 0;
    }
    return 1;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1, u, v; i<n; i++)
    {
        cin>>u>>v;
        g[u].eb(v);
        g[v].eb(u);
    }
    int l=n, r=1e9, ans=1e9;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
