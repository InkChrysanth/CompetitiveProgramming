//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
constexpr int mod=998244353;

signed main()
{
	setIO();
    int T; cin>>T;
    while(T--)
    {
        int n, m; cin>>n>>m;
        vector<vector<pii>> g(n+2);
        for(int i=1; i<=m; i++)
        {
            int u, v, w; cin>>u>>v>>w;
            g[u-1].eb(mp(v, w));
            g[v].eb(mp(u-1, -w));
        }
        for(int i=1; i<=n; i++)
            g[n+1].eb(mp(i, 0));
        vector<int> dist(n+2, inf), cnt(n+2);
        vector<bool> vis(n+2);
        queue<int> q;
        q.push(n+1); vis[n+1]=true; dist[n+1]=0;
        bool flag=false;
        while(q.size())
        {
            int u=q.front(); q.pop();
            vis[u]=0;
            each(t, g[u])
            {
                int v=t.fi, w=t.se;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    cnt[v]=cnt[u]+1;
                    if(cnt[v]>=n+2)
                    {
                        flag=true;
                        goto label;
                    }
                    if(!vis[v]) q.push(v), vis[v]=1;
                }
            }
        }
        label:
        cout<<(flag ? "false" : "true")<<endl;
    }
	return 0;
}
// graphs(spfa)