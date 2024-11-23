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
	setIO("segment");
    int n, q; cin>>n>>q;
    vector<vector<int>> f(n+1, vector<int>(n+1));
    vector<vector<int>> a(n+1, vector<int>(n+1)), sum(n+1, vector<int>(n+1));
    vector<int> cnt(n+1);
    for(int i=1; i<=q; i++)
    {
        int l, r; cin>>l>>r;
        a[l][r]++;
        for(int k=l; k<r; k++) cnt[k]++;
    }
    for(int l=1; l<=n; l++)
        for(int r=n; r>=l; r--)
            sum[l][r]=sum[l-1][r]+sum[l][r+1]-sum[l-1][r+1]+a[l][r];
    for(int len=2; len<=n; len++)
        for(int l=1; l+len-1<=n; l++)
        {
            int r=l+len-1;
            f[l][r]=inf;
            for(int k=l; k<r; k++)
                cmin(f[l][r], f[l][k]+f[k+1][r]+cnt[k]-sum[l][r]);
        }
    cout<<f[1][n]+q<<endl;
	return 0;
}