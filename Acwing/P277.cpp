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

const int N=31, M=5010;
int n, m;
pii a[N];
int f[N][M];
int s[N];
int ans[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
	For(i, 1, n)
	{
		rd(a[i].fi);
		a[i].se=i;
	}
	sort(a+1, a+n+1, [](pii p, pii q){
		return p.fi>q.fi;
	});
	For(i, 1, n) s[i]=s[i-1]+a[i].fi;
//	For(i, 1, n) cerr<<a[i].fi<<' ';
//	For(i, 1, n) cerr<<s[i]<<' ';
	memset(f, inf, sizeof f);
	f[0][0]=0;
	For(i, 1, n)
	{
		For(j, i, m)
		{
			f[i][j]=f[i][j-i];
			For(k, 1, i)
			{
				f[i][j]=min(f[i][j], f[i-k][j-k]+(s[i]-s[i-k])*(i-k));
			}
		}
	}
	cout<<f[n][m]<<endl;
	int i=n, j=m, cnt=0;
	while(i && j)
	{
		if(j>i && f[i][j]==f[i][j-i]) cnt++, j-=i;
		else
		{
			For(k, 1, i)
			{
				if(f[i][j]==f[i-k][j-k]+(s[i]-s[i-k])*(i-k))
				{
					For(p, i-k+1, i)
					{
						ans[a[p].se]=cnt+1;
					}
					i-=k, j-=k;
					break;
				}
			}	
		}
	}
	For(i, 1, n) cout<<ans[i]<<' ';
	return 0;
}
