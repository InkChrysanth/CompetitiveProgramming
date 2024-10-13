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
constexpr int N=510, M=200010;
constexpr ld eps=1e-8;

int n, m;
int in[N];
ld a[N][N], b[M], f[M];
vector<int> g[N];
pii e[M];

void gauss()
{
	for(int i=1; i<n; i++)
	{
		int t=i;
		for(int j=i+1; j<n; j++)
			if(abs(a[t][i])<abs(a[j][i]))
				t=j;
		if(abs(a[t][i])<=eps) continue;
		swap(a[i], a[t]);
		for(int j=1; j<n; j++)
		{
			if(i==j) continue;
			ld div=a[j][i]/a[i][i];
			for(int k=i; k<=n; k++)
				a[j][k]-=a[i][k]*div;
		}
	}
}

signed main()
{
	Fre("move");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int u, v;
		cin>>u>>v;
		e[i]=mp(u, v);
		g[u].eb(v); g[v].eb(u);
		in[u]++; in[v]++;
	}
	for(int i=1; i<n; i++)
	{
		a[i][i]=1.0;
		each(v, g[i]) if(v!=n)
			a[i][v]=-1.0/in[v];
	}
	a[1][n]=1.0;
	gauss();
//	for(int i=1; i<n; i++, cerr<<endl)
//		for(int j=1; j<=n; j++)
//			cerr<<a[i][j]<<" ";
	for(int i=1; i<n; i++)
		b[i]=a[i][n]/a[i][i];
	for(int i=1; i<=m; i++)
	{
		int u=e[i].fi, v=e[i].se;
		f[i]=b[u]/in[u]+b[v]/in[v];
	}
	sort(f+1, f+m+1);
	ld ans=0;
	for(int i=1; i<=m; i++)
		ans+=f[i]*(m-i+1);
	cout<<fixed<<setprecision(3)<<ans<<endl;
	return 0;
}
// math(gauss), graphs, greedy