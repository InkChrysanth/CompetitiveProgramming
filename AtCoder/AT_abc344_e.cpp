// Problem: [ABC344E] Insert or Erase
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc344_e
// Memory Limit: 1 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
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

const int N=400010;
int n, m, a[N];
vector<int> e[N];
unordered_map<int, int> id;
bool st[N];

void dfs(int u)
{
	if(!st[u]) cout<<a[u]<<' ';
	reverse(all(e[u]));
	for(auto p: e[u])
		dfs(p);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n);
	For(i, 1, n)
	{
		rd(a[i]);
		id[a[i]]=i;
		e[i-1].eb(i);
	}
	rd(m);
	while(m--)
	{
		int op, x, y; rd(op, x);
		if(op==1)
		{
			rd(y); a[++n]=y;
			id[y]=n; e[id[x]].eb(id[y]);
		}
		else st[id[x]]=1;
	}
	dfs(1);
	return 0;
}