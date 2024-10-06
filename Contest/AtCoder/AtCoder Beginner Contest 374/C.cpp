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
	int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int ans=inf;
    for(int i=0; i<=(1<<(n+1))-1; i++)
    {
        int sa=0, sb=0;
        for(int k=0; k<n; k++)
        {
            if((i>>k)&1) sa+=a[k];
            else sb+=a[k];
        }
        cmin(ans, max(sa, sb));
    }
    cout<<ans<<endl;
	return 0;
}
// implementation, bitmasks