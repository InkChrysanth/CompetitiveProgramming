#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
int n, q, cnt;
vector<set<int>> g(N);

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, q); cnt=n;
	For(i, 1, q)
	{
		int op, u, v, k; rd(op);
		if(op==1)
		{
			rd(u, v);
			if(!g[u].size()) cnt--;
			if(!g[v].size()) cnt--;
			g[u].insert(v); g[v].insert(u);
		}
		else
		{
			rd(k);
			if(g[k].size()) cnt++;
			for(int x: g[k])
			{
				g[x].erase(k);
				if(!g[x].size()) cnt++;
			}
			g[k].clear();
		}
		cout<<cnt<<endl;
	}
	return 0;
}
