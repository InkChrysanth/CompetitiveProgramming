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
using pdd=pair<ld, ld>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

struct Node{ pdd a, b; };
ld calc(pdd a, pdd b, ld sp)
{ return sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se))/sp; }

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
    ld s, t; cin>>s>>t;
    vector<Node> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i].a.fi>>a[i].a.se>>a[i].b.fi>>a[i].b.se;
    vector<int> ord(n+1);
    iota(all(ord), 0);
    ld ans=1e40;
    do
    {
        for(int i=0; i<(1<<n); i++)
        {
            ld res=0; pdd cur=mp(0, 0);
            for(int k=0; k<n; k++)
            {
                pdd x=a[ord[k]].a, y=a[ord[k]].b;
                if((i>>k)&1) swap(x, y);
                res+=calc(cur, x, s);
                res+=calc(x, y, t);
                cur=y;
            }
            cmin(ans, res);
        }
    }while(next_permutation(all(ord)));
    cout<<setprecision(30)<<ans<<endl;
	return 0;
}
// implementation, bitmasks