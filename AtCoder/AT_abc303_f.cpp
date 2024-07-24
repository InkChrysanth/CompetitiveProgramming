//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using lll=__int128;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
    ll h;
    cin>>n>>h;
    vector<array<ll, 3>> a(n);
    each(i, a)
    {
        cin>>i[1]>>i[2];
        i[0]=i[1]*i[2];
        i[1]=-i[1];
    }
    sort(all(a), [](const auto &x, const auto &y){ return x[1]>y[1]; });
    vector<array<ll, 3>> pre(n);
    pre[0]=a[0];
    for(int i=1; i<n; i++)
    {
        pre[i]=max(pre[i-1], a[i]);
        //t*d(greater), t(less), d(greater)
    }
    auto check=[&](ll x)
    {
        int pos=n-1;
        lll cur=h, mx=0;
        while(cur>0 && x>0)
        {
            while(pos>=0 && -pre[pos][1]>x)
            {
                cmax(mx, (lll)a[pos][2]);
                pos--;
            }
            if(pos<0 || pre[pos][0]<mx*x)
            {
                lll cnt=x-((pos>=0)?pre[pos][0]/mx:0);
                lll sum=(x+x-cnt+1)*cnt/2*mx;
                cur-=sum, x-=cnt;
            }
            else
            {
                lll cnt=x-(-pre[pos][1])+1;
                lll sum=pre[pos][0]*cnt;
                cur-=sum, x-=cnt;
            }
        }
        return cur<=0;
    };
    ll l=0, r=1e18, ans=1e18;
	while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid-1, ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
