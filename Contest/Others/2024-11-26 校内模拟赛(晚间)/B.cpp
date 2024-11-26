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
    int n, m; cin>>n>>m;
    if(m>100) return cout<<0<<endl, 0;
    vector<ll> a(n), b(m);
    each(x, a) cin>>x;
    each(x, b) cin>>x;
    auto f=[&](auto &&f, vector<ll> vec, int i)
    {
        if(vec.empty()) return 0ll;
        if(i==m) return accumulate(all(vec), 0ll);
        vector<ll> vec1, vec2;
        each(x, vec)
        {
            if(x%b[i]==0) vec1.eb(x);
            else vec2.eb(x);
        }
        if(i&1) return max(f(f, vec1, i+1), f(f, vec2, i+1));
        else return min(f(f, vec1, i+1), f(f, vec2, i+1));
    };
    cout<<f(f, a, 0)<<endl;
    return 0;
}
// number theory, implementation, game theory, math