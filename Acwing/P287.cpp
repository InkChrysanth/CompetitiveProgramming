//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define mtp make_tuple
#define pb push_back
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 0, 1, -1, 1, -1};

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

const int N=200010;
int n;
vector<pii> g[N];
int deg[N], f[N], d[N];
bool vis[N];

void dp(int u)
{
	vis[u]=1;
	each(t, g[u])
	{
		int v=t.fi, w=t.se;
		if(vis[v]) continue;
		dp(v);
		if(deg[v]==1) d[u]+=w;
		else d[u]+=min(d[v], w);
	}
}

void dfs(int u)
{
	vis[u]=1;
	each(t, g[u])
	{
		int v=t.fi, w=t.se;
		if(vis[v]) continue;
		if(deg[v]==1) f[v]=min(f[u]-w, w);
		else if(deg[u]==1) f[v]=d[v]+w;
		else f[v]=d[v]+min(f[u]-min(w, d[v]), w);
		dfs(v);
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	int T;
	rd(T);
	while(T--)
	{
		rd(n);
		For(i, 1, n) g[i].clear(), d[i]=deg[i]=vis[i]=f[i]=0;
		For(i, 1, n-1)
		{
			int u, v, w;
			rd(u, v, w);
			g[u].eb(mp(v, w));
			g[v].eb(mp(u, w));
			deg[u]++;
			deg[v]++;
		}
		dp(1);
		f[1]=d[1];
		For(i, 1, n) vis[i]=0;
		dfs(1);
		cout<<(*max_element(f+1, f+n+1))<<endl;
	}
	return 0;
}
