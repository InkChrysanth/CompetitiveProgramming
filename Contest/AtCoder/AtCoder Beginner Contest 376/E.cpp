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
	int T; cin>>T;
    while(T--)
    {
        int n, k; cin>>n>>k;
        vector<pii> a(n+1);
        for(int i=1; i<=n; i++) cin>>a[i].fi;
        for(int i=1; i<=n; i++) cin>>a[i].se;
        sort(a.begin()+1, a.begin()+n+1);
        priority_queue<int> heap;
        ll ans=llinf, sum=0;
        for(int i=1; i<=n; i++)
        {
            sum+=a[i].se;
            heap.em(a[i].se);
            while(heap.size()>k)
            {
                sum-=heap.top();
                heap.pop();
            }
            if(heap.size()==k) cmin(ans, 1ll*sum*a[i].fi);
        }
        cout<<ans<<endl;
    }
	return 0;
}
// greedy(with backtracking)