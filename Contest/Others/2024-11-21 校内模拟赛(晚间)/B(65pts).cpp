#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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

int main()
{
    cin.tie(0);
    int n, q; cin>>n>>q;
    vector<vector<int>> g(n+1);
    for(int i=1; i<=n-1; i++)
    {
        int u, v; cin>>u>>v;
        g[u].eb(v); g[v].eb(u);
    }
    vector<bool> vis(n+1), col(n+1);
    vector<int> dist(n+1);
    int mx=0, id;
    function<void(int, int, int)> dfs=[&](int u, int par, int dep)
    {
        if(dep>=mx && !col[u]) mx=dep, id=u;
        each(v, g[u]) if(v!=par)
            dfs(v, u, dep+1);
    };
    bool flag=true;
    while(q--)
    {
        char opt; cin>>opt;
        if(opt=='C')
        {
            int x; cin>>x;
            col[x]=col[x]^1;
            flag=true;
        }
        else
        {
            if(flag)
            {
                mx=0; dfs(1, 0, 0);
                mx=0; dfs(id, 0, 0);
                flag=false;
            }
            cout<<mx<<endl;
        }
    }
    return 0;
}