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

int a[500010];
int f[11][2000010], g[2000010];
// f[i,j,k]=f[i-1,j,k]+f[i-1,j-1,k^a[i]]
signed main()
{
    setIO();
    int n, s, sum=0; cin>>n>>s;
    for(int i=1; i<=n; i++) cin>>a[i], sum^=a[i];
    sort(a+1, a+n+1);
    f[0][0]=1;
    int u=1;
    for(int i=1; i<=n; i++)
    {
        while(u<=a[i]) u<<=1;
        for(int k=0; k<u; k++)
            g[k]=(f[0][k]+f[s-1][k^a[i]])%mod;
        for(int j=s-1; j>=1; j--)
            for(int k=0; k<u; k++)
                f[j][k]=(f[j][k]+f[j-1][k^a[i]])%mod;
        for(int k=0; k<u; k++)
            f[0][k]=g[k];
    }
    if(n%s==0) f[0][sum]--;
    cout<<(f[0][sum]+mod)%mod<<endl;
    return 0;
}
// dp, game theory