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
constexpr int mod=1e9+7;

ll qmi(ll a, ll k)
{
    a%=mod;
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

struct ODT
{
    struct Node
    {
        int l, r;
        mutable int v;
	    Node(int l, int r, int v): l(l), r(r), v(v) {}
	    bool operator<(const Node &T)const { return l<T.l; }
    };
    set<Node> S;
    void init(int T, int n){ S.ins(Node(0, T, n)); }
    auto split(int pos)
    {
        auto it=prev(S.upper_bound(Node(pos, 0, 0)));
        if(it->l==pos) return it;
        int l=it->l, r=it->r, v=it->v;
        S.erase(it);
        S.ins(Node(l, pos-1, v));
        return S.ins(Node(pos, r, v)).fi;
    }
    void modify(int l, int r, int v)
    {
        auto itr=split(r+1), itl=split(l);
        for(; itl!=itr; ++itl) itl->v+=v;
    }
    ll query(int l, int r)
    {
        auto itr=split(r+1), itl=split(l);
        ll res=1;
        for(; itl!=itr; ++itl)
            res=res*qmi(itl->v, itl->r-itl->l+1)%mod;
        return res;
    }
} odt;

signed main()
{
	setIO("travel");
    int n, m, S, T; cin>>n>>m>>S>>T; T-=S;
    odt.init(T, n);
    for(int i=1; i<=m; i++)
    {
        int l, r, _; cin>>_>>l>>r;
        l-=S, r-=S;
        odt.modify(l, r, -1);
    }
    cout<<odt.query(0, T)<<endl;
	return 0;
}
// data structures, math