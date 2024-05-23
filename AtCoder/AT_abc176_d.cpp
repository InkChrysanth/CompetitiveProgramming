// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define y0 y114514
#define y1 y1919810
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define For(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define Rep(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define all(s) s.begin(), s.end()
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

const int N=1010;
int h, w;
bool g[N][N];
int dis[N][N];
pii st, ed;
list<pii> dq;

bool check(int x, int y)
{
	if(x<1 || x>h || y<1 || y>w || g[x][y]) return false;
	return true;
}

void bfs()
{
	memset(dis, 0x3f, sizeof dis);
	dis[st.fi][st.se]=0;
	dq.push_front(mp(st.fi, st.se));
	while(dq.size())
	{
		auto u=dq.front(); dq.pop_front();
		For(i, 1, 4)
		{
			auto v=mp(u.fi+dx[i], u.se+dy[i]);
			if(!check(v.fi, v.se)) continue;
			if(dis[v.fi][v.se]<=dis[u.fi][u.se]) continue;
			dq.push_front(v);
			dis[v.fi][v.se]=dis[u.fi][u.se];
		}
		For(x, u.fi-2, u.fi+2) For(y, u.se-2, u.se+2)
		{
			if(!check(x, y)) continue;
			if(dis[x][y]<=dis[u.fi][u.se]+1) continue;
			dq.push_back(mp(x, y));
			dis[x][y]=dis[u.fi][u.se]+1;
		}
	}
}
signed main()
{
	cin.tie(0); cout.tie(0);
	rd(h, w, st.fi, st.se, ed.fi, ed.se);
	For(i, 1, h) For(j, 1, w)
	{
		char c; cin>>c;
		g[i][j]=(c=='#');
	}
	bfs();
	cout<<((dis[ed.fi][ed.se]==0x3f3f3f3f)?-1:dis[ed.fi][ed.se])<<endl;
	return 0;
}
