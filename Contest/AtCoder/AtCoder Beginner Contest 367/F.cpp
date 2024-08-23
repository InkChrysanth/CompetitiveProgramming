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

random_device seed;
mt19937_64 rnd(seed());
map<int, ll> hs;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<ull> a(n+1, 0), b(n+1, 0);
	for(int i=1; i<=n; i++) cin>>a[i], a[i]=(hs[a[i]] ? hs[a[i]] : hs[a[i]]=rnd());
    for(int i=1; i<=n; i++) cin>>b[i], b[i]=(hs[b[i]] ? hs[b[i]] : hs[a[i]]=rnd());
    partial_sum(a.begin()+1, a.begin()+n+1, a.begin()+1);
    partial_sum(b.begin()+1, b.begin()+n+1, b.begin()+1);
    for(int la, lb, ra, rb; q--;)
    {
        cin>>la>>ra>>lb>>rb;
        cout<<(a[ra]-a[la-1]==b[rb]-b[lb-1] ? "Yes" : "No")<<endl;
    }
    return 0;
}
