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
constexpr int mod=10007;

signed main()
{
	setIO();
    int n, k; cin>>n>>k;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];// chinese
    for(int i=1; i<=n; i++) cin>>b[i];// math
    vector<vector<array<ll, 2>>> f(n+1, vector<array<ll, 2>>(k+1));
    // 1: chinese   0: math
    f[0][0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(j) f[i][j][1]=a[i]%mod*(f[i-1][j-1][0]+f[i-1][j-1][1])%mod;
            f[i][j][0]=b[i]%mod*(f[i-1][j][0]+f[i-1][j][1])%mod;
        }
        f[i][k][1]=(f[i-1][k][1]+f[i-1][k][0])*a[i]%mod+(f[i-1][k-1][0]+f[i-1][k-1][1])*a[i]%mod;
        f[i][k][0]=(f[i-1][k][1]+f[i-1][k][0])*b[i]%mod;
    }
    // debug(f[n][k][0]); debug(f[n][k][1]);
    cout<<(f[n][k][0]+f[n][k][1])%mod<<endl;
	return 0;
}
// dp