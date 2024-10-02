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
	int n, m; ll k;
    cin>>n>>m>>k;
    if(n==m)
    {
        for(int i=1; i<=n; i++)
            cout<<0<<" ";
        return 0;
    }
    vector<pll> a(n+1);
    for(int i=1; i<=n; i++)
    {
        ll x; cin>>x;
        a[i]=mp(x, i);
        k-=x;
    }
    sort(a.begin()+1, a.begin()+n+1, greater<pll>());
    vector<ll> s(n+1);
    for(int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i].fi;
    vector<ll> ans(n+1);
    auto check=[&](int pos, ll x)
    {
        if(a[pos].fi+x<a[m].fi)
            return false;
        int l=1, r=m, res=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[pos].fi+x>=a[mid].fi) r=mid-1, res=mid;
            else l=mid+1;
        }
        return (a[pos].fi+x+1)*(m-res+1)-(s[m]-s[res-1])
        +(pos<=m)*(a[pos].fi+x+1-(a[m+1].fi+x+1))>k-x;
    };
    for(int i=1; i<=n; i++)
    {
        if(a[i].fi+k<a[m].fi)
            ans[a[i].se]=-1;
        else
        {
            ll l=0, r=k, res=r;
            while(l<=r)
            {
                ll mid=(l+r)>>1;
                if(check(i, mid))
                    r=mid-1, res=mid;
                else l=mid+1;
            }
            ans[a[i].se]=res;
        }
    }
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
	return 0;
}
