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
constexpr int N=2010;

ll a[N][N];

signed main()
{
    setIO();
    int n, m; cin>>n>>m;
    while(m--)
    {
        int r, c, l, s; cin>>r>>c>>l>>s;
        for(int i=r; i<r+l; i++)
            a[i][c]+=s, a[i][i-r+c+1]-=s;
    }
    ll res=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a[i][j]+=a[i][j-1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            res^=a[i][j];
    cout<<res<<endl;
    return 0;
}
// difference, implementation, brute force