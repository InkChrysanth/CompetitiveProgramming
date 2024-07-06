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

const int N=110, M=20010, D=10000;

int n, m;
int w[N];
int pre[N];
int f[N][M];// i: pos, j: sum, 1: +, -1: - 


signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
	m+=D;
	For(i, 1, n) rd(w[i]);
	f[1][w[1]+D]=1;
	f[2][w[1]-w[2]+D]=-1;
	For(i, 3, n)
	{
		For(j, 0, 20000)
		{
			if(f[i-1][j])
			{
				f[i][j-w[i]]=-1;
				f[i][j+w[i]]=1;
			}
		}
	}
	Rep(i, n, 2)
	{
		pre[i]=f[i][m];
		m+=(pre[i]==1?-1:1)*w[i];
	}
	int cnt=0;
	For(i, 2, n)
	{
		if(pre[i]==1)
		{
			cout<<i-cnt-1<<endl;
			cnt++;
		}
	}
	For(i, 1, cnt)
	{
		cout<<1<<endl;
	}
	return 0;
}
