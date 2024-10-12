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
constexpr int N=100010;

struct Fenwick
{
    ll f[N];
    int lowbit(int x){ return x&-x; }
    void modify(int x, ll v){ for(; x<N; x+=lowbit(x)) cmax(f[x], v); }
    int query(int x){ ll res=-inf; for(; x; x-=lowbit(x)) cmax(res, f[x]); return res; }
    void clear(int x){ for(; x<N; x+=lowbit(x)) f[x]=-inf; }
} tr;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T; cin>>T;
    while(T--)
    {
        int n, k; cin>>n>>k;
        vector<ll> a(n+1), cand;
        for(int i=1; i<=n; i++) cin>>a[i], a[i]+=a[i-1], cand.eb(a[i]);
        cand.eb(0);
        sort(all(cand));
        cand.erase(unique(all(cand)), cand.end());
        ll l=-1e16, r=1e16, ans=r;
        auto check=[&](ll x)
        {
            for(int i=1; i<=cand.size(); i++) tr.clear(i);
            tr.modify(cand.size()-(lower_bound(all(cand), 0)-cand.begin()+1)+1, 0);
            int res=0;
            for(int i=1; i<=n; i++)
            {
                int p=lower_bound(all(cand), a[i]-x)-cand.begin()+1;
                int val=tr.query(cand.size()-p+1)+1;
                p=lower_bound(all(cand), a[i])-cand.begin()+1;
                tr.modify(cand.size()-p+1, val);
                cmax(res, val);
            }
            return res>=k;
        };
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(check(mid)) r=mid-1, ans=mid;
            else l=mid+1;
        }
        cout<<ans<<endl;
    }
	return 0;
}
// data structures(BIT), dp, binary search