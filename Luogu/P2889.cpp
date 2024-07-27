#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
	int n;
	cin>>n;
	vector<int> a(n+1, 0);
	for(int i=1; i<=n; i++) cin>>a[i], a[i]+=a[i-1];
	vector<vector<int>> f(n+2, vector<int>(n+2, 0)), p(n+2, vector<int>(n+2, 0));
	for(int i=1; i<=n; i++) p[i][i]=i;
	for(int len=2; len<=n; len++)
	{
		for(int l=1; l+len-1<=n; l++)
		{
		    int r=l+len-1;
			f[l][r]=inf;
			for(int k=p[l][r-1]; k<=p[l+1][r]; k++)
			{
			    int t=f[l][k]+f[k+1][r]+a[r]-a[l-1];
			    if(t<f[l][r])
			    {
			        f[l][r]=t;
			        p[l][r]=k;
			    }
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
