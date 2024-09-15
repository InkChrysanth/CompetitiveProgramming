//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".ans")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int mod=998244353;

ll qmi(ll a, ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}
ll C(ll a, ll b)
{
    if(a<b) return 0;
    ll res=1;
    for(int i=1, j=a; i<=b; i++, j--)
    {
        res=res*j%mod;
        res=res*qmi(i, mod-2)%mod;
    }
    return res;
}
ll lucas(ll a, ll b)
{
    if(b==0) return 1;
    return C(a%mod, b%mod)*lucas(a/mod, b/mod)%mod;
}

signed main()
{
    Fre("array");
	cin.tie(0)->sync_with_stdio(0);
    int T, L, R;
    cin>>T>>L>>R;
    int D=R-L+1;
    cout<<(lucas(T+D, D)-lucas(T-1+D, D)+mod)%mod<<endl;
	return 0;
}
