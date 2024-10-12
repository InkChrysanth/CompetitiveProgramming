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
constexpr int N=110, M=510;

int n, a[N], b[N], m;
int f[N][M][M];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i], m+=b[i];
    if(m%3) return cout<<"-1"<<endl, 0; m/=3;
    memset(f, 0x3f, sizeof f);
    f[0][0][0]=0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=m; j++)
            for(int k=0; k<=m; k++)
            {
                cmin(f[i][j][k], f[i-1][j][k]+(a[i]!=1));
                if(j>=b[i]) cmin(f[i][j][k], f[i-1][j-b[i]][k]+(a[i]!=2));
                if(k>=b[i]) cmin(f[i][j][k], f[i-1][j][k-b[i]]+(a[i]!=3));
            }
    cout<<(f[n][m][m]==inf ? -1 : f[n][m][m])<<endl;
	return 0;
}
// dp