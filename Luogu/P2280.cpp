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
constexpr int N=5010;

int a[N][N];

signed main()
{
	setIO();
    int n, m; cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int x, y, v; cin>>x>>y>>v;
        x++, y++;
        a[x][y]+=v;
    }
    for(int i=1; i<N; i++)
        for(int j=1; j<N; j++)
            a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
    int ans=0;
    for(int i=m; i<N; i++)
        for(int j=m; j<N; j++)
            cmax(ans, a[i][j]-a[i-m][j]-a[i][j-m]+a[i-m][j-m]);
    cout<<ans<<endl;
    return 0;
}
