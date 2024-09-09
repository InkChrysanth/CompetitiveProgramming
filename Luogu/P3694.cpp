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
constexpr int N=21, M=100010;

int f[1<<N];
int num[N], cnt[M][N];

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for(int i=1, x; i<=n; i++)
	{
		cin>>x;
		num[x]++;
		cnt[i][x]++;
		for(int k=1; k<=m; k++)
			cnt[i][k]+=cnt[i-1][k];
	}
	memset(f, 0x3f, sizeof f);
	f[0]=0;
	for(int st=1; st<(1<<m); st++)
	{
		int len=0;
		for(int i=1; i<=m; i++)
			if((st>>(i-1))&1)
				len+=num[i];
		for(int i=1; i<=m; i++)
			if((st>>(i-1))&1)
				cmin(f[st], f[st^(1<<(i-1))]+num[i]-(cnt[len][i]-cnt[len-num[i]][i]));
	}
//	for(int st=1; st<(1<<m); st++)
//		debug(st), debug(f[st]);
	cout<<f[(1<<m)-1]<<endl;
	return 0;
}
