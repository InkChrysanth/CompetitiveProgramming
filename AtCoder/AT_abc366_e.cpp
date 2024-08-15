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
constexpr int N=200010, M=4000010, D=2000000;

int n, d;
int x[N], y[N];
ll f[M], g[M];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>d;
    for(int i=1; i<=n; i++)
        cin>>x[i]>>y[i], f[0]+=x[i]+D, g[0]+=y[i]+D;
    sort(x+1, x+n+1); sort(y+1, y+n+1);
    int p=0;
    for(int i=-D+1; i<=D; i++)
    {
        while(x[p+1]<i && p+1<=n) p++;
        f[i+D]=f[i+D-1]+2*p-n;  
    }
    p=0;
    for(int i=-D+1; i<=D; i++)
    {
        while(y[p+1]<i && p+1<=n) p++;
        g[i+D]=g[i+D-1]+2*p-n;
    }
    sort(f, f+2*D+1); sort(g, g+2*D+1);
    // for(int i=0; i<=10; i++) debug(f[i]), debug(g[i]);
    ll ans=0;
    for(int i=0, j=2*D; i<=2*D; i++)
    {
        while(f[i]+g[j]>d && j-1>=0) j--;
        if(f[i]+g[j]<=d) ans+=j+1;
    }
    cout<<ans<<endl;
    return 0;
}
