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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T; cin>>T;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
        vector<ll> a(n+1), b(n+1);
        for(int i=1; i<=n; i++) cin>>a[i], b[i]=b[i-1]+(a[i]==1), a[i]+=a[i-1];
        // for(int i=1; i<=n; i++) cerr<<b[i]<<' ';
        // cerr<<endl;
        for(int i=1; i<=q; i++)
        {
            int l, r;
            cin>>l>>r;
            if(l==r) cout<<"NO"<<endl;
            else if(a[r]-a[l-1]<b[r]-b[l-1]+r-l+1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}
