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
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=300010;

ll a[N], s[N];
ll st1[N][20], st2[N][20];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i], s[i]=s[i-1]+a[i], st1[i][0]=st2[i][0]=a[i];
        for(int j=1; j<20; j++)
            for(int i=1; i+(1<<(j-1))<=n; i++)
            {
                st1[i][j]=min(st1[i][j-1], st1[i+(1<<(j-1))][j-1]);
                st2[i][j]=max(st2[i][j-1], st2[i+(1<<(j-1))][j-1]); 
            }
        auto getmin=[&](int l, int r) -> int
        {
            int k=log2(r-l+1);
            return min(st1[l][k], st1[r-(1<<k)+1][k]);
        };
        auto getmax=[&](int l, int r) -> int
        {
            int k=log2(r-l+1);
            return max(st2[l][k], st2[r-(1<<k)+1][k]);
        };
        auto check=[&](int l, int r) -> bool
        {
            return getmin(l, r)!=getmax(l, r);
        };
        for(int i=1; i<=n; i++)
        {
            int p1=-1, p2=-1, l=1, r=i-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if((s[i-1]-s[i-mid-1]>a[i] && check(i-mid, i-1)) || getmin(i-mid, i-1)>a[i])
                    p1=mid, r=mid-1;
                else l=mid+1;
            }
            l=1, r=n-i;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if((s[i+mid]-s[i+1-1]>a[i] && check(i+1, i+mid)) || getmin(i+1, i+mid)>a[i])
                    p2=mid, r=mid-1;
                else l=mid+1;
            }
            int res=inf;
            res=min({res, (~p1)?p1:inf, (~p2)?p2:inf});
            cout<<((res==inf)?-1:res)<<' ';
        }
        cout<<endl;
    }
    return 0;
}
