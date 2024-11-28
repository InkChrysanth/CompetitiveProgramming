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
constexpr int N=10000010;

vector<int> pri;
bool st[N];
void init()
{
    for(int i=2; i<N; i++)
    {
        if(!st[i]) pri.eb(i);
        for(int j=0; pri[j]*i<N; j++)
        {
            st[pri[j]*i]=true;
            if(i%pri[j]==0) break;
        }
    }
}

signed main()
{
    setIO(); init();
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i=1; i<=n; i++) cin>>a[i];
        int ans=n;
        vector<set<int>> g(n+1), rg(n+1);
        for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++)
            if(st[__gcd(a[i], a[j])])
                g[i].ins(j), g[j].ins(i);
        rg=g;
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++) if(g[i].count(k))
                g[i].erase(k);
            g[k].clear();
            vector<bool> vis(n+1);
            auto bfs=[&](int u)
            {
                int cnt=1;
                queue<int> q; q.push(u); vis[u]=true;
                while(q.size())
                {
                    int u=q.front(); q.pop();
                    each(v, g[u]) if(!vis[v])
                        cnt++, q.push(v), vis[v]=true;
                }
                return cnt;
            };
            int res=0;
            for(int i=1; i<=n; i++) if(!vis[i])
                cmax(res, bfs(i));
            cmin(ans, res);
            g=rg;
        }
        cout<<ans<<endl;
    }
    return 0;
}