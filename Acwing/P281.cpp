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

const int N=100010;
int n, m;
int v[N], s[N];
bool vis[N];
int f[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	while(rd(n, m), n&&m)
	{
		For(i, 1, n) rd(v[i]);
		For(i, 1, n) rd(s[i]);
		memset(vis, 0, sizeof vis);
		vis[0]=1;
		For(i, 1, n)
		{
			memset(f, 0, sizeof f);
			For(j, v[i], m)
			{
				if(!vis[j] && vis[j-v[i]] && f[j-v[i]]<s[i])
				{
					f[j]=f[j-v[i]]+1;
					vis[j]=1;
				}
			}
		}
		int ans=0;
		For(i, 1, m) ans+=vis[i];
		cout<<ans<<endl; 
	}
	return 0;
}
