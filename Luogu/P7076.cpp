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
    // Fre("test");
	cin.tie(0)->sync_with_stdio(0);
    int n, m, c, k;
    cin>>n>>m>>c>>k;
    ull res=0;
    for(int i=1; i<=n; i++)
    {
        ull x; cin>>x;
        for(int j=0; j<=k; j++)
            if((x>>j)&1llu) res|=(1llu<<j);
    }
    vector<bool> vis(k+1, false);
    int cnt=0;
    for(int i=1, p, q; i<=m; i++)
    {
        cin>>p>>q;
        if(vis[p]) continue;
        vis[p]=true;
        if(!((res>>p)&1llu)) cnt++;
    }
    // debug(cnt);
    if(k-cnt==64) return cout<<"184"<<46744073709551616-n<<endl, 0;
    cout<<(1llu<<(k-cnt))-n<<endl;
	return 0;
}
