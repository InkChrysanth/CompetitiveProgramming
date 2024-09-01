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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<array<ll, 2>> f(n+1);
    for(int i=1; i<=n; i++)
        cin>>a[i];
    f[1][1]=a[1], f[1][0]=0;
    for(int i=2; i<=n; i++)
    {
        f[i][0]=max(f[i-1][0], f[i-1][1]+a[i]*2);
        f[i][1]=max(f[i-1][0]+a[i], f[i-1][1]);
    }
    cout<<max(f[n][0], f[n][1])<<endl;
	return 0;
}
