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

const int N=210;

int n, T, tc;
int w[N];
int f[N][N][N];

int dp(int l, int r, int cnt)
{
	int &val=f[l][r][cnt];
	if(~val) return val;
	if(l>r) return val=0;
	val=dp(l, r-1, 0)+(1+cnt)*(1+cnt);
	For(k, l, r-1)
	{
		if(w[k]==w[r])
		{
			val=max(val, dp(l, k, cnt+1)+dp(k+1, r-1, 0));
		}
	}
	return val;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(T);
	while(T--)
	{
		printf("Case %d: ", ++tc);
		memset(f, -1, sizeof f);
		rd(n);
		For(i, 1, n) rd(w[i]);
		cout<<dp(1, n, 0)<<endl;
	}
	return 0;
}
