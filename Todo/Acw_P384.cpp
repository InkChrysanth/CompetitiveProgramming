//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
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

int n, m, st;
vector<pii> g[N];
int dist[N];
bool vis[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    __gnu_pbds::pq<pii, greater<pii>> heap;
    heap.push(mp(dist[st]=0, st));
    while(heap.size())
    {
        auto u=heap.top().se;
        heap.pop();
        if(vis[u]) continue;
        vis[u]=1;
        each(t, g[u])
        {
            int v=t.fi, w=t.se;
            if(!vis[v] && dist[u]+w<dist[v])
                heap.push(mp(dist[v]=dist[u]+w, v));
        }
    }
}

//https://www.acwing.com/solution/content/19234/
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	vector<int> a(m+1);
	for(int i=1; i<=m; i++)
	{
		cin>>a[i];
		if(!a[i]) st=a[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++) for(int k=1; k<=m; k++)
		{
			if(!a[k] || i+a[k]>n || i+a[k]<1) continue;
			g[(i-1)*m+j].eb(mp((i+a[k]-1)*m+k, abs(a[k]*2)+abs(k-j)));
		}
	}
	dijkstra();
	int ans=inf;
	for(int i=(n-1)*m+1; i<=n*m; i++) cmin(ans, dist[i]);
	cout<<((ans==inf)?-1:ans);
	return 0;
}
