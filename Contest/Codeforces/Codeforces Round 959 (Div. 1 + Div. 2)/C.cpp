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
constexpr int N=200010;

void solve()
{
    int n;
    ll lm;
    cin>>n>>lm;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    partial_sum(a.begin()+1, a.end(), a.begin()+1);
    // for(int i=1; i<=n; i++) cerr<<a[i]<<' ';
    // cerr<<endl;
    vector<ll> f(n+2);
    for(int i=n-1; i>=0; i--)
    {
        int p=upper_bound(a.begin()+1, a.end(), a[i]+lm)-a.begin();
        f[i]=f[p]+(p-i-1);
    }
    cout<<accumulate(all(f), 0ll)<<endl;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
    cin>>T;
    while(T--) solve();
	return 0;
}
