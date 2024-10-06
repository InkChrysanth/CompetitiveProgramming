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
	int n, k; ll x;
    cin>>n>>k>>x;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<ll> cand;
    for(int i=0; i<n; i++)
        for(int j=0; j<=n; j++)
            cand.eb(a[i]+j*x);
    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());
    vector<vector<ll>> f(cand.size()+1, vector<ll>(n, llinf));
    f[0][0]=0;
    ll ans=llinf;
    int nxt=0;
    for(int i=0; i<cand.size(); i++)
    {
        while(nxt<cand.size() && cand[nxt]<cand[i]+x) nxt++;
        for(int j=0; j<n; j++)
        {
            if(f[i][j]==llinf) continue;
            cmin(f[i+1][j], f[i][j]);
            // debug(f[i+1][j]);
            ll mv=f[i][j];
            for(int p=j; p<min(j+k, n); p++)
            {
                if(cand[i]<a[p]) break;
                mv+=(cand[i]-a[p]);
                if(p==n-1) cmin(ans, mv);
                else cmin(f[nxt][p+1], mv);
            }
        }
    }
    cout<<ans<<endl;
	return 0;
}
// dp