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
const int N=85;

string s1, s2, ans;
int n, m, len;
int f[N][N];

void dfs(int p1, int p2, int u)
{
	if(u==len+1)
	{
		For(i, 1, len) cout<<ans[i];
		cout<<endl;
		return;
	}
	if(s1[p1]==s2[p2])
	{
		ans[u]=s1[p1];
//		cerr<<ans[u]<<endl;
		dfs(p1+1, p2+1, u+1);
	}
	else 
	{
		For(i, 0, 25)
		{
			int pp1=0, pp2=0;
			For(j, p1, n)
			{
				if(s1[j]=='a'+i)
				{
					pp1=j;
					break;
				}
			}
			For(j, p2, m)
			{
				if(s2[j]=='a'+i)
				{
					pp2=j;
					break;
				}
			}	
			if(pp1 && pp2 && f[p1][p2]==f[pp1][pp2]) dfs(pp1, pp2, u);
		}
	}
}

signed main()
{
	cin.tie(0); cout.tie(0);
	cin>>s1>>s2;
	n=s1.size(), m=s2.size();
	s1=" "+s1, s2=" "+s2;
//	cerr<<s1<<n<<endl<<s2<<m;
	Rep(i, n, 1)
	{
		Rep(j, m, 1)
		{
			f[i][j]=max(f[i+1][j], f[i][j+1]);
			if(s1[i]==s2[j]) f[i][j]=max(f[i][j], f[i+1][j+1]+1);
		}
	}
	len=f[1][1];
//	cerr<<len<<endl;
	dfs(1, 1, 1);
	return 0;
}
