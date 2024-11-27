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
constexpr int mod=1000000007;

signed main()
{
    setIO();
    int n; cin>>n;
    vector<int> a(n+2), b(n+2);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    vector<int> sa(n+2);
    for(int i=1; i<=n; i++) sa[i]=(sa[i-1]+a[i])%mod;
    vector<int> psa(n+2), ssa(n+2);
    for(int i=1; i<=n; i++) psa[i]=(psa[i-1]+sa[i])%mod;
    for(int i=n; i>=1; i--) ssa[i]=(ssa[i+1]+sa[i])%mod;
    vector<int> p(n+2);
    for(int i=1; i<=n; i++)
        p[i]=(1ll*i*ssa[i]%mod-1ll*(n-i+1)*psa[i-1]%mod+mod)%mod;
    vector<int> sp(n+2);
    for(int i=1; i<=n; i++)
        sp[i]=(sp[i-1]+p[i])%mod;
    int ans=0;
    for(int i=1; i<=n; i++)
        ans=(ans+1ll*p[i]*b[i]%mod)%mod;
    cout<<ans<<endl;
    return 0;
}
// math