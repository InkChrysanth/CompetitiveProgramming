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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, mg, mh;
    cin>>n;
    vector<vector<int>> w(n+1, vector<int>(n+1, 0)); 
    vector<vector<bool>> g(n+1, vector<bool>(n+1, false)), h(n+1, vector<bool>(n+1, false));
    cin>>mg;
    for(int i=1; i<=mg; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u][v]=g[v][u]=true;
    }
    cin>>mh;
    for(int i=1; i<=mh; i++)
    {
        int u, v;
        cin>>u>>v;
        h[u][v]=h[v][u]=true;
    }
    for(int i=1; i<=n-1; i++)
        for(int j=i+1; j<=n; j++)
            cin>>w[i][j];
    vector<int> p(n+1);
    for(int i=1; i<=n; i++) p[i]=i;
    int ans=inf;
    do
    {
        int res=0;
        for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++)
        {
            if(h[i][j]!=g[p[i]][p[j]])
                res+=w[i][j];
        }
        cmin(ans, res);
    } while(next_permutation(p.begin()+1, p.begin()+n+1));
    cout<<ans<<endl;
	return 0;
}
