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
constexpr int N=6010;

int f[N][2], w[N];
vector<int> g[N];
bool st[N];

void dfs(int u)
{
    f[u][1]=w[u];
    each(v, g[u])
    {
        dfs(v);
        f[u][0]+=max(f[v][0], f[v][1]);
        f[u][1]+=f[v][0];
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>w[i];
    for(int i=1, u, v; i<=n-1; i++)
    {
        cin>>u>>v;
        g[v].eb(u);
        st[u]=1;
    }
    int root;
    for(int i=1; i<=n; i++)
        if(!st[i])
        {
            root=i;
            break;
        }
    dfs(root);
    cout<<max(f[root][0], f[root][1])<<endl;
	return 0;
}
