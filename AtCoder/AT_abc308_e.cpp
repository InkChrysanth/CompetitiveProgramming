// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
    vector<char> b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    vector<valarray<ll>> m(n+2, {0, 0, 0}), x(n+2, {0, 0, 0});
    for(int i=1; i<=n; i++)
    {
        if(b[i]=='M')
        {
            if(a[i]==0) m[i][0]++;
            if(a[i]==1) m[i][1]++;
            if(a[i]==2) m[i][2]++;
        }
        m[i]+=m[i-1];
    }
    for(int i=n; i>=1; i--)
    {
        if(b[i]=='X')
        {
            if(a[i]==0) x[i][0]++;
            if(a[i]==1) x[i][1]++;
            if(a[i]==2) x[i][2]++;
        }
        x[i]+=x[i+1];
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        if(b[i]=='E')
        {
            if(a[i]==0)
            {
                ans+=m[i][0]*x[i][0]*1;
                ans+=m[i][1]*x[i][0]*2;
                ans+=m[i][2]*x[i][0]*1;
                ans+=m[i][0]*x[i][1]*2;
                ans+=m[i][1]*x[i][1]*2;
                ans+=m[i][2]*x[i][1]*3;
                ans+=m[i][0]*x[i][2]*1;
                ans+=m[i][1]*x[i][2]*3;
                ans+=m[i][2]*x[i][2]*1;
            }
            if(a[i]==1)
            {
                ans+=m[i][0]*x[i][0]*2;
                ans+=m[i][1]*x[i][0]*2;
                ans+=m[i][2]*x[i][0]*3;
                ans+=m[i][0]*x[i][1]*2;
                ans+=m[i][1]*x[i][1]*0;
                ans+=m[i][2]*x[i][1]*0;
                ans+=m[i][0]*x[i][2]*3;
                ans+=m[i][1]*x[i][2]*0;
                ans+=m[i][2]*x[i][2]*0;
            }
            if(a[i]==2)
            {
                ans+=m[i][0]*x[i][0]*1;
                ans+=m[i][1]*x[i][0]*3;
                ans+=m[i][2]*x[i][0]*1;
                ans+=m[i][0]*x[i][1]*3;
                ans+=m[i][1]*x[i][1]*0;
                ans+=m[i][2]*x[i][1]*0;
                ans+=m[i][0]*x[i][2]*1;
                ans+=m[i][1]*x[i][2]*0;
                ans+=m[i][2]*x[i][2]*0;
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
