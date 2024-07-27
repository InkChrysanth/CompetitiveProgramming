//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a.begin()+1, a.end());
	vector<vector<int>> dis(n+2, vector<int>(n+2, 0));
	for(int l=1; l<=n; l++)
		for(int r=l+1; r<=n; r++)
			dis[l][r]=dis[l][r-1]+a[r]-a[(l+r)>>1];
	vector<vector<int>> f(n+1, vector<int>(m+1, inf));
	vector<vector<int>> p(n+2, vector<int>(m+2));
	f[0][0]=0;
	for(int j=1; j<=m; j++)
	{
		p[n+1][j]=n;
		for(int i=n; i>=j; i--)
		{
			for(int k=p[i][j-1]; k<=p[i+1][j]; k++)
			{
				int t=f[k][j-1]+dis[k+1][i]; 
				if(t<f[i][j])
				{
					f[i][j]=t;
					p[i][j]=k;
				}
			}
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
