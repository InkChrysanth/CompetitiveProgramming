#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,n) (i)=min((i),(n))
#define cmax(i,n) (i)=max((i),(n))
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
    int n; cin>>n;
    vector<vector<int>> g(1000001);
    while(n--)
    {
        int x; cin>>x;
        for(int i=2; i*i<=x; i++)
            while(x%(i*i)==0)
                x/=(i*i);
        if(x==1) return cout<<1<<endl, 0;
        g[1].eb(x), g[x].eb(1);
        for(int i=2; i*i<=x; i++) if(x%i==0)
            g[i].eb(x/i), g[x/i].eb(i);
    }
    int ans=inf;
    vector<int> pre(1000001);
    auto bfs=[&](int s)
    {
        vector<int> dist(1000001, inf);
        queue<int> q;
        q.push(s); dist[s]=0;
        while(q.size())
        {
            int u=q.front(); q.pop();
            each(v, g[u]) if(v!=pre[u])
            {
                cmin(ans, dist[u]+dist[v]+1);
                if(dist[v]==inf) pre[v]=u, dist[v]=dist[u]+1, q.push(v);
            }
        }
    };
    for(int i=1; i<=1000; i++) bfs(i);
    cout<<(ans==inf ? -1 : ans)<<endl;
    return 0;
}
// graphs, bfs and similar