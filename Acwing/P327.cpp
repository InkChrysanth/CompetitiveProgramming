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

const int N=13, MOD=100000000;

int n, m;
int g[N][N], s[N];
int f[N][1<<N];
vector<int> st;
vector<int> pre[1<<N];

signed main()
{
	cin.tie(0); cout.tie(0);
	auto calc=[](vector<int> v) -> int
	{
		int res=0;
		reverse(all(v));
		For(i, 0, v.size()-1) res+=pow(2, i)*v[i];
		return res;
	};
	auto check1=[](int st1) -> bool
	{
		For(i, 0, m-1) if((st1>>i&1) && (st1>>(i+1)&1)) return false;
		return true;
	}; 
	auto check2=[](int st1, int st2) -> bool
	{
		return !(st1&st2);
	};
	rd(n, m);
	For(i, 1, n)
	{
		vector<int> t;
		For(j, 1, m)
		{
			rd(g[i][j]);
			g[i][j]^=1;
			t.eb(g[i][j]);
		}
		s[i]=calc(t);
// 		debug(s[i]);
	}
	For(i, 0, (1<<m)-1) if(check1(i)) st.eb(i);
// 	debug(st.size());
	each(i, st) each(j, st) if(check2(i, j)) pre[i].eb(j);
	f[0][0]=1;
	For(i, 1, n)
	{
		int t=s[i];
		each(k, st) if(check2(t, k)) each(p, pre[k]) (f[i][k]+=f[i-1][p])%=MOD;
	}
	int ans=0;
	For(i, 0, (1<<m)-1) (ans+=f[n][i])%=MOD;
	cout<<ans<<endl;
	return 0;
}
