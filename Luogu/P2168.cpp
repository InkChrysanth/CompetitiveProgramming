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
    ll val; int dep;
    Node(ll val, int dep): val(val), dep(dep) {}
    bool operator<(const Node &T)const
    {
        if(val!=T.val) return val>T.val;
        return dep>T.dep;
    }
};
pq<Node> heap;

signed main()
{
	setIO();
    int n, k; cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        ll x; cin>>x;
        heap.emplace(x, 0);
    }
    if((n-1)%(k-1)) 
        for(int i=1; i<=(k-1-(n-1)%(k-1)); i++)
            heap.emplace(0, 0);
    ll ans=0;
    while(heap.size()>1)
    {
        int dep=0; ll val=0;
        for(int i=1; i<=k; i++)
        {
            auto u=heap.top(); heap.pop();
            val+=u.val;
            cmax(dep, u.dep);
        }
        ans+=val;
        heap.emplace(val, dep+1);
    }
    cout<<ans<<endl<<heap.top().dep<<endl;
	return 0;
}
