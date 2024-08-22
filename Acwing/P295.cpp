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
    int n, m;
    cin>>m>>n;
    vector<int> nxt(n+1, -1);
    for(int i=1, l, r; i<=m; i++)
    {
        cin>>l>>r;
        cmax(nxt[l], r);
    }
    for(int i=1; i<=n; i++)
        cmax(nxt[i], nxt[i-1]);
    // for(int i=1; i<=n; i++) cerr<<nxt[i]<<" \n"[i==n];
    int p=1, cnt=0;
    while(p<=n && nxt[p]>=p) p=nxt[p]+1, cnt++;
    cout<<(p<=n ? -1 : cnt)<<endl;
	return 0;
}
