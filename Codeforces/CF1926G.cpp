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
        int n; cin>>n;
        vector<vector<int>> g(n+1);
        for(int i=2; i<=n; i++)
        {
            int x; cin>>x;
            g[x].eb(i);
        }
        // 0: silence
        // 1: noise
        vector<array<int, 2>> f(n+1, {0, 0});
        string st; cin>>st; st="%"+st;
        function<void(int, int)> dfs=[&](int u, int par)
        {
            each(v, g[u])
            {
                dfs(v, u);
                f[u][0]+=min(f[v][0], f[v][1]+1);
                f[u][1]+=min(f[v][1], f[v][0]+1);
            }
            if(st[u]=='S') f[u][1]=inf;
            else if(st[u]=='P') f[u][0]=inf;
        };
        dfs(1, 1);
        cout<<min(f[1][0], f[1][1])<<endl;
    }
	return 0;
}
// dp, dfs and similar, trees