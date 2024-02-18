// Problem: P3523 [POI2011] DYN-Dynamite
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3523
// Memory Limit: 125 MB
// Time Limit: 1000 ms

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); ll f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template <typename T, typename...Args>
void read(T &first, Args &...args)
{
	read(first);
	read(args...);
}

const int N=300010;
int n, m, cnt;
array<bool, N> st;
vector<int> e[N];
array<int, N> f, g;

void dfs(int u, int fa, int x)
{
	f[u]=-inf, g[u]=inf;
	for(auto v: e[u])
	{
		if(v==fa) continue;
		dfs(v, u, x);
		f[u]=max(f[u], f[v]+1);
		g[u]=min(g[u], g[v]+1);
	}
	if(f[u]+g[u]<=x) f[u]=-inf;
	if(g[u]>x && st[u]) f[u]=max(f[u], 0);
	if(f[u]==x) f[u]=-inf, g[u]=0, cnt++;
}

bool check(int x)
{
	cnt=0;
	dfs(1, 0, x);
	if(f[1]!=-inf) cnt++;
	return cnt<=m;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
	for(int i=1; i<=n; i++) rd(st[i]);
	For(i, 1, n-1)
	{
		int u, v; rd(u, v);
		e[u].eb(v), e[v].eb(u);
	}
	int l=0, r=n, ans=m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid, r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}