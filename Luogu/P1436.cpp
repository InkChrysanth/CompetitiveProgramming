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

const int N=10, M=20;
int n;
int a[N][N];
int s[N][N];
int f[N][N][N][N][M];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n);
	For(i, 1, 8) For(j, 1, 8) rd(a[i][j]);
	For(i, 1, 8) For(j, 1, 8) s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	auto sum=[](int x1, int y1, int x2, int y2) -> int{
		int t=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
		return t*t;
	};
// 	debug(sum(1, 1, 8, 8));
	For(k, 1, n) For(x1, 1, 8) For(y1, 1, 8) For(x2, 1, 8) For(y2, 1, 8)
	{
		auto &val=f[x1][y1][x2][y2][k];
		val=inf;
		if(k==1) val=sum(x1, y1, x2, y2);
		else
		{
			For(i, x1, x2-1)
				val=min({val, f[x1][y1][i][y2][k-1]+sum(i+1, y1, x2, y2), f[i+1][y1][x2][y2][k-1]+sum(x1, y1, i, y2)});
			For(i, y1, y2-1)
				val=min({val, f[x1][y1][x2][i][k-1]+sum(x1, i+1, x2, y2), f[x1][i+1][x2][y2][k-1]+sum(x1, y1, x2, i)});
		}
	}
	cout<<f[1][1][8][8][n]<<endl;
	return 0;
}
