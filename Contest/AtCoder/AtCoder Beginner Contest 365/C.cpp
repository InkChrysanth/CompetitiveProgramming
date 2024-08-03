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
    int n; ll k, sum=0;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i], sum+=a[i];
    if(sum<=k)
    {
        cout<<"infinite"<<endl;
        return 0;
    }
    auto check=[&](ll mid)
    {
        ll res=0;
        for(int i=1; i<=n; i++) res+=min(a[i], mid);
        return res<=k;
    };
    ll l=0, r=1e15, ans=r;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1, ans=mid;
        else r=mid-1;
    }
    cout<<ans<<endl;
	return 0;
}
