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
const int N=210;

int n, m, tot;
map<string, int> hs;
int w[N], sz[N];
bool extfa[N];
vector<int> g[N];
int f[N][N];

void dp(int u)
{
	f[u][0]=0;
	sz[u]=1;
	each(v, g[u])
	{
		dp(v);
		sz[u]+=sz[v];
	}
	each(v, g[u])
	{
		Rep(i, sz[u], 1) For(k, 1, min(i, sz[v]))
		{
			f[u][i]=min(f[u][i], f[u][i-k]+f[v][k]);
		}
	}
	For(i, 1, sz[u]) f[u][i]=min(f[u][i], w[u]);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	while(cin>>n>>m)
	{
	    getchar();
		hs.clear();
		For(i, 0, n) g[i].clear();
		memset(extfa, 0, sizeof extfa);
		tot=0;
		memset(f, inf, sizeof f);
		For(i, 1, n)
		{
			string t;
			getline(cin, t);
			stringstream ss(t);
			string co, cco;
			ss>>co;
// 			debug(co);
			hs[co]=++tot;
			ss>>w[tot];
			while(ss>>cco)
			{
				if(!hs[cco]) hs[cco]=++tot;
				extfa[hs[cco]]=1;
				g[hs[co]].eb(hs[cco]);
			}
		}
		For(i, 1, n) if(!extfa[i]) g[0].eb(i);//, debug(w[i]);
		w[0]=inf;
		dp(0);
		cout<<f[0][m]<<endl;
	}
	return 0;
}
