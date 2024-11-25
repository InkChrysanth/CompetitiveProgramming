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
constexpr int N=1000010, K=22;

ll phi[N], mx[N], f[N];
vector<int> pri;
bool notPrime[N];

void init()
{
    phi[1]=1;
    for(int i=2; i<N; i++)
    {
        if(!notPrime[i])
        {
            pri.eb(i);
            phi[i]=i-1;
        }
        each(p, pri)
        {
            if(i*p>N) break;
            notPrime[i*p]=true;
            if(i%p==0){ phi[i*p]=p*phi[i]; break; }
            phi[i*p]=phi[i]*phi[p];
        }
    }
    for(int i=1; i<N; i++) mx[i]=max(mx[i-1], phi[i]);
}

signed main()
{
    setIO(); init();
    int T, B; cin>>T>>B;
    for(int i=1; i<N; i++)
    {
        ll k=mx[i]-B, a=i;
        if(k<=0) f[i]=i;
        else if(k<1145)
        {
            for(int j=1; j<=k; j++) a=phi[a];
            f[i]=a;
        }
        else f[i]=1;
    }
    for(int i=1; i<N; i++) f[i]+=f[i-1];
    if(B==1e9)
    {
        while(T--)
        {
            int l, r; cin>>l>>r;
            cout<<1ll*(l+r)*(r-l+1)/2<<endl;
        }
        return 0;
    }
    while(T--)
    {
        int l, r; cin>>l>>r;
        if(r>=N)
        {
            int dl=0, dr=0;
            if(l>=N) dl=l-N+1;
            dr=r-N+1;
            l-=dl, r-=dr;
            cout<<f[r]-f[l-1]-dl+dr<<endl;
        }
        else cout<<f[r]-f[l-1]<<endl;
    }
    return 0;
}
// math, implementation