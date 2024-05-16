//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
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
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={1, 0, -1, 0, 1, -1, 1, -1};

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

struct Node
{
	int a, b, s, t;
}bus[N];

int n, m, q;
int dp[N][21];
set<pii> st[N];

int query(int x, int k)
{
	auto it=st[x].lower_bound(mp(k, 0));
	if(it==st[x].end()) return 0;
	return (*it).se;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m, q);
	For(i, 1, m)
	{
		rd(bus[i].a, bus[i].b, bus[i].s, bus[i].t);
		st[bus[i].a].insert(mp(bus[i].s, i));
	}
	For(i, 1, m) dp[i][0]=query(bus[i].b, bus[i].t);
	For(j, 1, 20)
		For(i, 1, m)
			dp[i][j]=dp[dp[i][j-1]][j-1];
	while(q--)
	{
		int x, y, z; rd(x, y, z);
		int p=query(y, x);
		if(!p) cout<<y<<endl;
		else
		{
			Rep(i, 20, 0)
			{
				if(dp[p][i] && bus[dp[p][i]].s<z)
					p=dp[p][i];
			}
			if(bus[p].s>=z) cout<<bus[p].a<<endl;
			else if(bus[p].t<z) cout<<bus[p].b<<endl;
			else cout<<bus[p].a<<' '<<bus[p].b<<endl;
		}
	}
	return 0;
}
