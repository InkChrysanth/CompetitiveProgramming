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

signed main()
{
	setIO("colorful");
    int n, m; cin>>n>>m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    vector<int> cnt(1000001);
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
        cin>>a[i][j];
    ll ans=1ll*n*m*(n+1)*(m+1)/4;/*alert: signed int overflow*/
	for(int i=1; i<=n; i++) for(int k=1; k<=i; k++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[k][j]==a[i][j])
            {
                cnt[a[i][j]]++;
                ans-=cnt[a[i][j]];
            }
        }
        for(int j=1; j<=m; j++) if(a[k][j]==a[i][j])
            cnt[a[i][j]]--;
    }
    cout<<ans<<endl;
    return 0;
}
// prefix sum, brute force, math