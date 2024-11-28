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

signed main()
{
    setIO();
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        vector<multiset<int>> g(n+1);
        map<pii, int> cnt;
        queue<pii> q;
        auto add=[&](int u, int v)
        {
            if(u>v) swap(u, v);
            g[u].ins(v), g[v].ins(u);
            if(++cnt[mp(u, v)]==2) q.push(mp(u, v));
        };
        for(int i=1; i<=2*n-2; i++)
        {
            int u, v; cin>>u>>v;
            add(u, v);
        }
        int s=0;
        while(q.size() && s<n-1)
        {
            int i=q.front().fi, j=q.front().se; q.pop();
            if(!cnt[mp(i, j)]) continue;
            if(g[i].size()>g[j].size()) swap(i, j);
            each(k, g[i])
            {
                cnt[mp(min(i, k), max(i, k))]--;
                g[k].erase(g[k].find(i));
                add(j, k);
            }
            g[i].clear();
            s++;
        }
        cout<<(s==n-1 ? "YES" : "NO")<<endl;
    }
    return 0;
}