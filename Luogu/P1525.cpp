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

struct Node{ int a, b, w;};

signed main()
{
	setIO();
	int n, m; cin>>n>>m;
    vector<Node> rel(m);
    each(x, rel) cin>>x.a>>x.b>>x.w;
    vector<int> p(2*n+1);
    iota(all(p), 0);
    function<int(int)> find=[&](int x)
    { return x==p[x] ? x : p[x]=find(p[x]); };
    sort(all(rel), [](Node a, Node b){ return a.w>b.w; });
    each(x, rel)
    {
        int a=x.a, b=x.b, w=x.w;
        int fa=find(a), fb=find(b);
        if(fa==fb) return cout<<w<<endl, 0;
        p[fa]=find(b+n), p[fb]=find(a+n);
    }
    cout<<0<<endl;
	return 0;
}
// dsu, greedy