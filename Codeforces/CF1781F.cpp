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

const int N=510, MOD=998244353;
int n, x, y;
ll f[N][N], C[N][N];
ll g[N][N];

ll qmi(ll a, ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1) res=res*a%MOD;
		a=a*a%MOD;
		p>>=1;
	}
	return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, x);
	ll p=x*qmi(10000, MOD-2)%MOD;
	// debug(p);
	C[0][0]=1;
	For(i, 1, n)
	{
		C[i][0]=1;
		For(j, 1, i)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
	For(i, 0, n) f[0][i]=g[0][i]=1;
	For(i, 1, n)
	{
		For(j, 0, i)
		{
			For(k, 0, i-1)
			{
				f[i][j]=(f[i][j]+p%MOD*f[i-k-1][j+1]%MOD*g[k][j]%MOD*C[i-1][k])%MOD;
				if(j) f[i][j]=(f[i][j]+(1-p+MOD)%MOD*f[i-k-1][j-1]%MOD*g[k][j]%MOD*C[i-1][k])%MOD;
			}
			For(k, 0, i)
			{
				g[i][j]=(g[i][j]+f[k][j]%MOD*f[i-k][j]%MOD*C[i][k])%MOD;
			}
		}
		For(j, i+1, n)
		{
			f[i][j]=f[i][j-1];
			g[i][j]=g[i][j-1];
		}
	}
	ll ans=f[n][0];
	// debug(f[n][0]);
	For(i, 1, n) ans=ans*qmi(2*i-1, MOD-2)%MOD;
	cout<<ans<<endl;
	return 0;
}
