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
    int n, m;
    cin>>n>>m;
    vector<int> a(n+1), b(m+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];
    
    auto check_slopea=[&](int i, int j, int k)
    { return (ll)(a[k]-a[j])*(j-i) > (ll)(a[j]-a[i])*(k-j); };
    auto check_slopeb=[&](int i, int j, int k)
    { return (ll)(b[k]-b[j])*(j-i) > (ll)(b[j]-b[i])*(k-j); };

	vector<int> qa(n+1)/*column*/, qb(m+1)/*row*/;
    int ha=1, ta=0, hb=1, tb=0;
    qa[++ta]=1, qb[++tb]=1;
    for(int i=2; i<=n; i++)
    {
        while(ha<ta && !check_slopea(qa[ta-1], qa[ta], i)) ta--;
        qa[++ta]=i;
    }
    for(int i=2; i<=m; i++)
    {
        while(hb<tb && !check_slopeb(qb[tb-1], qb[tb], i)) tb--;
        qb[++tb]=i;
    }

    auto check_dir=[&](int i, int j, int k, int l)
    { return (ll)(a[i]-a[k])*(l-j) > (ll)(b[j]-b[l])*(k-i); };

    ll ans=0;
    while(ha<ta || hb<tb)
    {
        if(hb==tb || (ha<ta && check_dir(qa[ha], qb[hb], qa[ha+1], qb[hb+1])))//go right
            ans+=(ll)(qa[ha+1]-qa[ha])*b[qb[hb]], ha++;
        else//go down
            ans+=(ll)(qb[hb+1]-qb[hb])*a[qa[ha]], hb++;
    }
    cout<<ans<<endl;
    return 0;
}
