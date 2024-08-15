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
constexpr int N=110;

int n, q;
int a[N][N][N];
int s[N][N][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
        cin>>a[k][i][j], s[k][i][j]=s[k-1][i][j]+a[k][i][j];
    // for(int k=1; k<=n; k++)
    // {
    //     for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
    //         cout<<s[k][i][j]<<" \n"[j==n];
    //     cout<<endl;
    // } 
    cin>>q;
    for(int i, j, k, _i, _j, _k; q>0; q--)
    {
        cin>>k>>_k>>i>>_i>>j>>_j;
        int ans=0;
        for(int p=i; p<=_i; p++) for(int q=j; q<=_j; q++)
            ans+=s[_k][p][q]-s[k-1][p][q];
        cout<<ans<<endl;
    }
	return 0;
}
