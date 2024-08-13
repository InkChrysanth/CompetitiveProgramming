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
constexpr int N=81, M=10010;

int n, x, y;
int f[N][M];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x>>y;
    memset(f, 0x3f, sizeof f);
    f[0][0]=0;
    for(int i=1, a, b; i<=n; i++)
    {
        cin>>a>>b;
        for(int j=n; j>=1; j--)
            for(int k=x; k>=a; k--)
                cmin(f[j][k], f[j-1][k-a]+b);
    }
    for(int i=n; i>=0; i--)
        for(int j=1; j<=x; j++) 
            if(f[i][j]<=y)
                return cout<<min(i+1, n)<<endl, 0;
    cout<<1<<endl;
	return 0;
}
