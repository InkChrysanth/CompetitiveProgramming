// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

struct cmp1
{
    bool operator()(const auto &x, const auto &y)
    {
        if(x.se.size()!=y.se.size())
            return x.se.size()>y.se.size();
        return x.se>y.se;
    }
};

struct cmp2
{
    bool operator()(const auto &x, const auto &y)
    {
        return x.se>y.se;
    }
};

signed main()
{
    setIO();
    int n, m; cin>>n>>m;
    vector<vector<pair<int, string>>> g(n+1);
    for(int i=1; i<=m; i++)
    {
        int u, v; string w; cin>>u>>v>>w;
        g[u].eb(mp(v, w));
    }
    vector<bool> vis1(n+1);
    vector<bool> vis2(n+1);
    pq<pair<int, string>, vector<pair<int, string>>, cmp1> q1;
    pq<pair<int, string>, vector<pair<int, string>>, cmp2> q2;
    q1.push(mp(1, ""));
    while(q1.size())
    {
        auto u=q1.top(); q1.pop();
        if(u.fi==n)
        {
            cout<<u.se<<" ";
            break;
        }
        if(vis1[u.fi]) continue;
        vis1[u.fi]=true;
        each(t, g[u.fi])
        {
            int v=t.fi; string w=t.se;
            if(true)
                q1.push(mp(v, u.se+w));
        }
    }
    q2.push(mp(1, ""));
    while(q2.size())
    {
        auto u=q2.top(); q2.pop();
        if(u.fi==n)
        {
            cout<<u.se<<" ";
            break;
        }
        if(vis2[u.fi]) continue;
        vis2[u.fi]=true;
        each(t, g[u.fi])
        {
            int v=t.fi; string w=t.se;
            if(true)
                q2.push(mp(v, u.se+w));
        }
    }
    return 0;
}
// graphs(dijkstra)