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

struct Node
{
    ll c, d;
    Node(ll c, ll d): c(c), d(d){}
};

signed main()
{
	setIO();
	int n, m; cin>>n>>m;
    vector<vector<pair<int, Node>>> g(n+1);
    for(int i=1; i<=m; i++)
    {
        int a, b, c, d; cin>>a>>b>>c>>d;
        g[a].eb(mp(b, Node(c, d)));
        g[b].eb(mp(a, Node(c, d)));
    }
    //  x + 1/x >= 2 sqrt(x * 1/x)
    vector<ll> dist(n+1, llinf);
    auto work=[](Node w, ll cur)
    {
        ll c=w.c, d=w.d;
        array<ll, 2> cand={sqrt(d), sqrt(d)-1};
        ll res=c+(d/(cur+1));
        for(int i=0; i<2; i++) if(cand[i]>=cur)
            cmin(res, c+(d/(cand[i]+1))+cand[i]-cur);
        return res;
    };
    auto dijkstra=[&]()
    {
        vector<bool> vis(n+1);
		priority_queue<pll, vector<pll>, greater<pll>> heap;
        heap.push(mp(dist[1]=0, 1));
        while(heap.size())
        {
            auto u=heap.top(); heap.pop();
            if(vis[u.se]) continue;
            vis[u.se]=true;
            each(t, g[u.se])
            {
                int v=t.fi; ll w=work(t.se, dist[u.se]);
                if(!vis[v] && dist[v]>dist[u.se]+w)
                    heap.push(mp(dist[v]=dist[u.se]+w, v));
            }
        }
        return dist[n]==llinf ? -1 : dist[n];
    };
    cout<<dijkstra()<<endl;
	return 0;
}
// graphs(dijkstra), math