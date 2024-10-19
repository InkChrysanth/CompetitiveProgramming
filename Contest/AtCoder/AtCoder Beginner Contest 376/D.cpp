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
	int n, m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].eb(v);
    }
    vector<int> dist(n+1, inf);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        each(v, g[u])
        {
            if(dist[v]!=inf && v!=1) continue;
            if(v==1 && dist[v]==0) dist[v]=dist[u]+1;
            else cmin(dist[v], dist[u]+1);
            q.push(v);
        }
    }
    cout<<(dist[1]==0 ? -1 : dist[1])<<endl;
	return 0;
}
// bfs