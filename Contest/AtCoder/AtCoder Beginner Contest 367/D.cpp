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
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010;

int n, p; ll ans=0;
int w[N<<1], s[N<<1];
map<int, int> cnt;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>p;
    for(int i=1; i<=n; i++)
        cin>>w[i], w[n+i]=w[i];
    for(int i=1; i<=n*2; i++)
        s[i]=(s[i-1]+w[i])%p;
    for(int i=1; i<=n; i++) cnt[s[i]]++;
    for(int i=1; i<=n; i++)
    {
        cnt[s[i]]--;
        ans+=cnt[s[i+n]];
        cnt[s[i+n]]++;
    }
    cout<<ans<<endl;
	return 0;
}
