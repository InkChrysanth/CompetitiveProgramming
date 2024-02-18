// Problem: P3942 将军令
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3942
// Memory Limit: 256 MB
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

const int N=100010;
int n, m, t, cnt=0;
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
	if(g[u]>x) f[u]=max(f[u], 0);
	if(f[u]==x) f[u]=-inf, g[u]=0, cnt++;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m, t);
	For(i, 1, n-1)
	{
		int u, v; rd(u, v);
		e[u].eb(v), e[v].eb(u);
	}
	dfs(1, 0, m);
	if(f[1]!=-inf) cnt++;
	cout<<cnt<<endl;
	return 0;
}