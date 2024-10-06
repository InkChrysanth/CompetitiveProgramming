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

struct Node{ ll a, p, b, q; };

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; ll x;
    cin>>n>>x;
    vector<Node> m(n+1);
    for(int i=1; i<=n; i++)
    {
        ll a, p, b, q;
        cin>>a>>p>>b>>q;
        if(a*q<b*p) swap(a, b), swap(p, q);
        m[i]={a, p, b, q};
    }
    auto check=[&](ll mid)
    {
        ll cost=0;
        for(int i=1; i<=n; i++)
        {
            ll a=m[i].a, b=m[i].b, p=m[i].p, q=m[i].q;
            ll res=llinf;
            for(int j=0; j<=100; j++)
            {
                ll v=j*q;
                int need=mid-j*b;
                if(need>0) v+=(need+a-1)/a*p;
                cmin(res, v);
            }
            cost+=res;
        }
        return cost<=x;
    };
    ll l=0, r=1000000000, ans=l;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1, ans=mid;
        else r=mid-1;
    }
    cout<<ans<<endl;
	return 0;
}
// binary search