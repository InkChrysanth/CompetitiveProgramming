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
    int u, v, w;
    Node(int u, int v, int w): u(u), v(v), w(w){}
    bool operator<(const Node &T)const { return w<T.w; }
};

signed main()
{
	setIO("speed");
	int n, m, k; cin>>n>>m>>k;
    vector<Node> E;
    for(int i=1; i<=m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        u--, v--;// use 0-indexed
        E.eb(u, v, w);
    }
    sort(all(E));
    vector<int> p(n);
    iota(all(p), 0);
    // each(x, p) debug(x);
    function<int(int)> find=[&](int x)
    { return x==p[x] ? x: p[x]=find(p[x]); };
    ll ans=llinf, res=0, cnt=0;
	bool flag=false;
    each(e, E)
    {
        int fu=find(e.u), fv=find(e.v);
        if(cnt<n-1)
        {
        	if(fu!=fv && e.w>=k) res+=(e.w-k), flag=true;
			if(fu!=fv) p[fu]=fv, cnt++; 
		}
		else
		{
			if(flag) return cout<<res<<endl, 0;
			cmin(ans, (ll)abs(k-e.w));
		}
    }
    cout<<ans<<endl;
	return 0;
}
// graphs, dsu