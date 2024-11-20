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
	int T; cin>>T;
    while(T--)
    {
        int n, m, k; cin>>n>>m>>k;
        vector<vector<pii>> g(n+1);
        vector<int> st(k+2);
        vector<int> p(n+1);
        iota(all(p), 0);
        function<int(int)> find=[&](int x)
        { return x==p[x] ? x : p[x]=find(p[x]); };
        vector<int> id(n+1);
        for(int i=1; i<=k+1; i++) cin>>st[i], id[st[i]]=i;
        for(int i=1; i<=k; i++)
        {
            g[st[i]].eb(mp(st[i+1], 1));
            p[find(st[i])]=st[i+1];
        }
        for(int i=1; i<=m-k; i++)
        {
            int u, v; cin>>u>>v;
            if(u==v) continue;
            if(find(u)==find(v))
            {
                if(id[u]<id[v]) g[u].eb(mp(v, 1));
                if(id[v]<id[u]) g[v].eb(mp(u, 1));
            }
        }
        vector<int> dist(n+1, inf);
        vector<bool> vis(n+1);
        pq<pii> heap; 
        heap.push(mp(dist[1]=0, 1));
        while(heap.size())
        {
            int u=heap.top().se; heap.pop();
            if(vis[u]) continue;
            vis[u]=true;
            each(t, g[u])
                if(!vis[t.fi] && dist[t.fi]>dist[u]+t.se)
                    dist[t.fi]=dist[u]+t.se, heap.push(mp(-dist[t.fi], t.fi));
        }
        cout<<dist[n]<<endl;
    }
	return 0;
}
// graphs(dijkstra)