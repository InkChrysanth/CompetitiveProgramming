//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    vector<pii> a(n+1);
    for(int i=1; i<=n; i++)
        cin>>a[i].fi>>a[i].se;
    sort(a.begin()+1, a.begin()+n+1, [](const auto &x, const auto &y){
        return (x.fi-1)*y.se<(y.fi-1)*x.se;
    });
    vector<vector<ll>> f(n+1, vector<ll>(k+1));
    f[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        f[i][0]=f[i-1][0];
        for(int j=1; j<=min(i, k); j++)
            f[i][j]=max(f[i-1][j], f[i-1][j-1]*a[i].fi+a[i].se);
    }
    cout<<f[n][k]<<endl;
	return 0;
}
