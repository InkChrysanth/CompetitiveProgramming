//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
constexpr int N=200010, mod=998244353;

int a[N], f[N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    int n, k, cnt=0;
    cin>>n>>k;
    map<int, int> m;
    m[0]=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
        f[i]=(cnt+1-m[a[i]-k]+mod)%mod;
        cnt=(cnt+f[i])%mod;
        m[a[i]]=(m[a[i]]+f[i])%mod;
    }
    cout<<f[n]<<endl;
	return 0;
}
