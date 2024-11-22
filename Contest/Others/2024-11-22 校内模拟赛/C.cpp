//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,t) (i)=min((i),(t))
#define cmax(i,t) (i)=max((i),(t))
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
constexpr int mod=998244353;

signed main()
{
	setIO();
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    vector<vector<int>> g(n+1);
    map<pii, bool> E;
    for(int i=1; i<=m; i++)
    {
        int u, v; cin>>u>>v;
        E[mp(u, v)]=E[mp(v, u)]=true;
        g[u].eb(v), g[v].eb(u);
    }
	set<int> S;
    for(int i=1; i<=n; i++) S.ins(i);
    vector<int> dist(n+1, inf);
    queue<int> q;
    q.push(s); S.erase(s); dist[s]=0;
    while(q.size())
    {
        int u=q.front(); q.pop();
        vector<int> del;
        each(v, S)
        {
            if(E[mp(u, v)]) continue;
            q.push(v); dist[v]=dist[u]+1;
            del.eb(v);
        }
        each(v, del) S.erase(v);
        if(S.empty()) break;
    }
    if(dist[t]==inf) return cout<<-1<<endl, 0;
    vector<vector<int>> st(n+1);
    for(int i=1; i<=n; i++) if(dist[i]!=inf)
        st[dist[i]].eb(i);
    vector<ll> cnt(n+1); cnt[s]=1;
    for(int i=1; i<=dist[t]; i++)
    {
        ll sum=0;
        each(u, st[i-1]) sum=(sum+cnt[u])%mod;
        each(u, st[i])
        {
            ll res=sum;
            each(par, g[u]) if(dist[par]+1==dist[u])
                res=(res-cnt[par]+mod)%mod;
            cnt[u]=res%mod;
        }
    }
    cout<<cnt[t]<<endl;
	return 0;
}
// bfs and similar, graphs, data structures