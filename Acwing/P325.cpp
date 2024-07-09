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
const int N=10010;

int n;

void solve()
{
	vector<pii> g[N];
	vector<int> nxt(n+1);
	For(u, 2, n)
	{
		int v, w;
		rd(v, w);
		g[u].eb(mp(v, w));
		g[v].eb(mp(u, w));
	}
	vector<int> dist0(n+1);
	vector<int> dist1(n+1);
	vector<int> dist2(n+1);
	function<void(int, int)> dfs1=[&](int u, int fa) -> void
	{
		each(t, g[u])
		{
			int v=t.fi, w=t.se;
			if(v==fa) continue;
			dfs1(v, u);
			if(dist0[v]+w>dist0[u])
			{
				dist0[u]=dist0[v]+w;
				nxt[u]=v;
			}
		}
		each(t, g[u])
		{
			int v=t.fi, w=t.se;
			if(v==fa) continue;
			if(v==nxt[u]) continue;
			dist1[u]=max(dist1[u], dist0[v]+w);
		}
	};
	function<void(int, int)> dfs2=[&](int u, int fa) -> void
	{
		each(t, g[u])
		{
			int v=t.fi, w=t.se;
			if(v==fa) continue;
			if(v==nxt[u]) dist2[v]=max(dist2[u], dist1[u])+w;
			else dist2[v]=max(dist2[u], dist0[u])+w;
			dfs2(v, u);
		}
	};
	dfs1(1, -1);
	dfs2(1, -1);
	For(i, 1, n) cout<<max(dist0[i], dist2[i])<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	while(cin>>n) solve();
	return 0;
}