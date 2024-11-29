//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	setIO();
	int n, m, k, S, T;
    cin>>n>>m>>k>>S>>T;
    vector<vector<pii>> g(n+k*n);
    for(int i=1; i<=m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        g[u].eb(mp(v, w));
        g[v].eb(mp(u, w));
        for(int j=1; j<=k; j++)
        {
            g[u+(j-1)*n].eb(mp(v+j*n, 0));
            g[v+(j-1)*n].eb(mp(u+j*n, 0));
            g[u+j*n].eb(mp(v+j*n, w));
            g[v+j*n].eb(mp(u+j*n, w));
        }
    }
    auto dijkstra=[&]()
    {    
        vector<bool> vis(n+k*n);
	    vector<int> dist(n+k*n, inf);
        pq<pii, vector<pii>, greater<pii>> heap;
        heap.push(mp(dist[S]=0, S));
        while(heap.size())
        {
            auto u=heap.top().se; heap.pop();
            if(vis[u]) continue;
            vis[u]=true;
            each(t, g[u])
            {
                int v=t.fi, w=t.se;
                if(dist[v]>dist[u]+w)
                    heap.push(mp(dist[v]=dist[u]+w, v));
            }
        }
        int res=inf;
        for(int i=0; i<=k; i++) cmin(res, dist[T+i*n]);
        return res;
    };
    cout<<dijkstra()<<endl;
	return 0;
}
// graphs(dijkstra)