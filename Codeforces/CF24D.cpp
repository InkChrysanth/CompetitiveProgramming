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
constexpr int N=1010;
constexpr ld eps=1e-6;

int n, m, x, y;
ld a[N][N], f[N][N];

void guass()
{
    ld t;
    for(int i=1; i<=m; i++)
    {
        t=a[i][i];
        a[i][i]/=t, a[i][i+1]/=t;
        if(i!=m) a[i][m+1]/=t;
        t=a[i+1][i];
        a[i+1][i]-=t*a[i][i], a[i+1][i+1]-=t*a[i][i+1];
        if(i!=m) a[i+1][m+1]-=t*a[i][m+1];
    }

    for(int i=m; i>=1; i--)
    {
        a[i-1][m+1]-=a[i-1][i]*a[i][m+1];
        a[i-1][i]-=a[i-1][i]*a[i][i];
    }
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>x>>y;
    if(m==1) cout<<2*(n-x)<<endl, exit(0);
    for(int i=n-1; i>=x; i--)
    {
        a[1][1]=a[m][m]=2.0/3;
        a[1][2]=a[m][m-1]=-1.0/3;
        a[1][m+1]=f[i+1][1]/3+1;
        a[m][m+1]=f[i+1][m]/3+1;

        for(int j=2; j<=m-1; j++)
        {
            a[j][j-1]=a[j][j+1]=-1.0/4;
            a[j][j]=3.0/4;
            a[j][m+1]=f[i+1][j]/4+1;
        }
        
        guass();

        for(int j=1; j<=m; j++)
            f[i][j]=a[j][m+1];
    }
    cout<<fixed<<setprecision(16)<<f[x][y]<<endl;
	return 0;
}
