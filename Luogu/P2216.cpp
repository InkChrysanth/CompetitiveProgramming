//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
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
#define pq priority_queue
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
const int N=1010;

int n, m, k, ans=inf;
int w[N][N];
int mn[N][N], mx[N][N];
int a[N], b[N];
int c[N], d[N];
int q[N];

void get_max(int a[], int f[], int n)
{
	int hh=0, tt=-1;
	For(i, 1, n)
	{
		while(hh<=tt && i-q[hh]>=k) hh++;
		while(hh<=tt && a[i]>=a[q[tt]]) tt--;
		q[++tt]=i;
		f[i]=a[q[hh]];
	}
}
void get_min(int a[], int f[], int n)
{
	int hh=0, tt=-1;
	For(i, 1, n)
	{
		while(hh<=tt && i-q[hh]>=k) hh++;
		while(hh<=tt && a[i]<=a[q[tt]]) tt--;
		q[++tt]=i;
		f[i]=a[q[hh]];
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m, k);
	For(i, 1, n) For(j, 1, m) rd(w[i][j]);
	For(i, 1, n)
	{
		get_min(w[i], mn[i], m);
		get_max(w[i], mx[i], m);
	}
	For(j, k, m)
	{
		For(i, 1, n)
		{
			a[i]=mn[i][j];
			b[i]=mx[i][j];
		}
		get_min(a, c, n);
		get_max(b, d, n);
		For(i, k, n) cmin(ans, abs(c[i]-d[i]));
	}
	cout<<ans<<endl;
	return 0;
}
