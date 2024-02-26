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
typedef pair<ll, int> pli;

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



const int N=100010, P=500000, M=1000010;
int n, m, st;
int a[N], leaf[N];
ll dist[M];
bool vis[M];
vector<pii> g[M];

struct Node
{
	int l, r;
}tr[N<<2];

void build(int o, int l, int r)
{
	tr[o].l=l, tr[o].r=r;
	if(l==r)
	{
		leaf[l]=o;
		return;
	}
	int mid=(l+r)>>1;
	g[o].eb(mp(o<<1, 0)); g[o].eb(mp(o<<1|1, 0));
	g[(o<<1)+P].eb(mp(o+P, 0)); g[(o<<1|1)+P].eb(mp(o+P, 0));
	build(o<<1, l, mid); build(o<<1|1, mid+1, r);
}

void add(int o, int u, int l, int r, int w, int dir)
{
	if(l<=tr[o].l && r>=tr[o].r)
	{
		if(dir) g[o+P].eb(mp(u, w));
		else g[u].eb(mp(o, w));
		return;
	}
	int mid=(tr[o].l+tr[o].r)>>1;
	if(l<=mid) add(o<<1, u, l, r, w, dir);
	if(r>mid) add(o<<1|1, u, l, r, w, dir);
}

void dijkstra()
{
	fill(dist+1, dist+M-10, llinf);
	priority_queue<pli, vector<pli>, greater<pli>> heap;
	heap.push(mp(dist[leaf[st]]=0, leaf[st]));
	while(heap.size())
	{
		int u=heap.top().se; heap.pop();
		if(vis[u]) continue; vis[u]=true;
		for(auto [v, w]: g[u])
			if(dist[v]>dist[u]+w)
				heap.push(mp(dist[v]=dist[u]+w, v));
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m, st);
	build(1, 1, n);
	For(i, 1, m)
	{
		int op, u, v, w, l, r;
		rd(op);
		if(op==1)
		{
			rd(u, v, w);
			g[leaf[u]].eb(mp(leaf[v], w));
		}
		else	
		{
			rd(u, l, r, w);
			add(1, leaf[u], l, r, w, op%2);
		}
	}
	For(i, 1, n) g[leaf[i]].eb(mp(leaf[i]+P, 0)), g[leaf[i]+P].eb(mp(leaf[i], 0));
	dijkstra();
	For(i, 1, n) cout<<(dist[leaf[i]]==llinf?-1:dist[leaf[i]])<<' ';
	return 0;
}