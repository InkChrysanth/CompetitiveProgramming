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
    int T;
    cin>>T;
    while(T--)
    {
        int n, k; cin>>n>>k;
        vector<pli> a(n+1);
        for(int i=1; i<=n; i++) cin>>a[i].fi;
        for(int i=1; i<=n; i++) cin>>a[i].se;
        sort(a.begin()+1, a.begin()+n+1);
        auto check=[&](ll mid)
        {
            int cnt=n-n/2; ll sum=0;
            for(int i=n-1; i>=1; i--)
            {
                if(a[i].fi>=mid) cnt--;
                else if(cnt>0 && a[i].se) cnt--, sum+=mid-a[i].fi;
            }
            return cnt<=0 && sum<=k;
        };
        ll l=0, r=2e9, res=r, ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) l=mid+1, res=mid;
            else r=mid-1;
        }
        cmax(ans, a[n].fi+res);
        bool flag=0;
        for(int i=n; i>=1; i--)
            if(a[i].se)
            {
                swap(a[n], a[i]);
                flag=1;
                break;
            }
        sort(a.begin()+1, a.begin()+n);
        if(flag) cmax(ans, a[n].fi+a[n/2].fi+k);
        cout<<ans<<endl;
    }
	return 0;
}
