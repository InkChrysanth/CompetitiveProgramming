// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
    Fre("water");
	cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    if(n==m){ return cout<<0<<" "<<n<<endl, 0; }
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a.begin()+1, a.begin()+n+1);
    for(int i=1; i<=n; i++)
    {
        int l=1, r=i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[mid]<=a[i]/2) l=mid+1;
            else r=mid-1, b[i]=mid;
        }
    }
    vector<array<int, 31>> f(n+1);
    for(int j=1; j<=30; j++)
        for(int i=1; i<=n; i++)
            f[i][j]=max(f[i-1][j], f[b[i]-1][j-1]+i-b[i]+1);
    for(int i=0; i<=30; i++) if(f[n][i]+m>=n)
    {
        cout<<i<<" "<<n-f[n][i]<<endl;
        break;
    }
    return 0;
}
// binary search, dp