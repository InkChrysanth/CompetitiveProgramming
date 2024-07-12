#pragma GCC optimize("Ofast,no-stack-protector,un\roll-loops")
#include <bits/stdc++.h>
#include <bits/extc++.h>
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
const int N=2010, M=30;

int n, m;
int a[N];
int f[M][N];
int d[N][N];

void solve()
{
	__gnu_pbds::pq<int> down, td;
	__gnu_pbds::pq<int, greater<int>> up, tu;
	For(i, 1, n) rd(a[i]);
	For(i, 1, n)
	{
		int sumd=0, sumu=0;
		down=td, up=tu;
		For(j, i, n)
		{
			if(!down.size() || a[j]<down.top()) down.push(a[j]), sumd+=a[j];
			else up.push(a[j]), sumu+=a[j];
			if(down.size()>up.size()+1) up.push(down.top()), sumu+=down.top(), sumd-=down.top(), down.pop();
			if(up.size()>down.size()) down.push(up.top()), sumd+=up.top(), sumu-=up.top(), up.pop();	
			int mid=down.top();
			d[i][j]=(mid*down.size()-sumd)+(sumu-mid*up.size());
		}
	}
	memset(f, inf, sizeof f);
	f[0][0]=0;
	For(i, 1, m) For(j, 1, n)
	{
		For(p, i-1, j-1)
			cmin(f[i][j], f[i-1][p]+d[p+1][j]);
	}
	cout<<f[m][n]<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	while(cin>>n>>m, n&&m) solve();	
	return 0;
}