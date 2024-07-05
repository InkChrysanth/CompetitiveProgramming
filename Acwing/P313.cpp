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

const int N=110;
int n, m;
int f[N][N];
int a[N][N];
int pos[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
	For(i, 1, n) For(j, 1, m)
	{
		rd(a[i][j]);
	}
	For(i, 1, n) For(j, 1, m) f[i][j]=-inf;
	For(i, 1, m) f[1][i]=a[1][i];
	For(i, 2, n)
		For(j, 1, m)
			For(k, 1, j-1)
				f[i][j]=max(f[i][j], f[i-1][k]+a[i][j]);
	int t=-inf;
	For(i, 1, m)
		if(f[n][i]>t)
			t=f[n][i], pos[n]=i;
	cout<<t<<endl;
	Rep(i, n, 2)
	{
		For(j, 1, m)
		{
			if(f[i][pos[i]]==f[i-1][j]+a[i][pos[i]])
			{
				pos[i-1]=j;
				break;
			}
		}
	}
	For(i, 1, n) cout<<pos[i]<<' ';
	return 0;
}
