//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(s) s.begin(), s.end()
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define fi first
#define se second
#define rd read
#define endl '\n'
#define mp make_pair
#define mtp make_tuple
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;

typedef long long ll;
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

const int N=300010;
int n, m, k, d;
vector<pii> g[N];
int vis[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
	For(i, 1, m)
	{
		int u, v, w;
		rd(u, v, w);
		g[u].eb(mp(v, w));
		g[v].eb(mp(u, w));
	}
	fill(vis+1, vis+n+1, -1);
	priority_queue<pii> q;
	rd(k);
	For(i, 1, k)
	{
		int u;
		rd(u);
		vis[u]=0;
		for(auto t: g[u]) q.push(mp(-t.se, t.fi));
	}
	rd(d);
	For(i, 1, d)
	{
		int l;
		rd(l);
		priority_queue<pii> p;
		while(q.size() && l+q.top().fi>=0)
		{
			int u=q.top().se, dis=l+q.top().fi;
			q.pop();
			if(~vis[u]) continue;
			p.push(mp(dis, u));
		}
		while(p.size())
		{
			int u=p.top().se, dis=p.top().fi;
			p.pop();
			if(~vis[u]) continue;
			vis[u]=i;
			for(auto t: g[u])
			{
				int v=t.fi, w=t.se;
				if(dis<w) q.push(mp(-w, v));
				else p.push(mp(dis-w, v));
			}
		}
	}
	For(i, 1, n) cout<<vis[i]<<endl;
	return 0;
}