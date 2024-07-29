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
using pdd=pair<double, double>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010;

int n;
pdd pts[N];

double calc(int i, int j)
{ return sqrt((pts[i].fi-pts[j].fi)*(pts[i].fi-pts[j].fi)+(pts[i].se-pts[j].se)*(pts[i].se-pts[j].se)); }

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>pts[i].fi>>pts[i].se;
	sort(pts+1, pts+n+1);
	double mn=1e18, mx=-1e18;
	for(int i=1; i<=n; i++)
	{
		for(int j=max(i-20, 1); j<=min(n, i+20); j++)
		{
			if(j==i) continue;
			cmin(mn, calc(i, j));
		}
		for(int j=1; j<=min(n, 20); j++)
			cmax(mx, calc(i, j));
		for(int j=n; j>=max(n-20, 1); j--)
			cmax(mx, calc(i, j));
	}
	cout<<fixed<<setprecision(15);
	cout<<mn<<' '<<mx<<endl;
	return 0;
}
