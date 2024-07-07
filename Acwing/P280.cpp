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

const int N=210, M=21, L=810, D=400;
int n, m;
int f[N][M][L], ans[M];// choose j people from 1 ... i, k: delta, val: di+pi(max)
int d[N], p[N];
int T;

signed main()
{
	cin.tie(0); cout.tie(0);
	while(rd(n, m), n&&m)
	{
		For(i, 1, n) rd(p[i], d[i]);
//		For(i, 1, n) debug(d[i]), debug(p[i]);
		memset(f, -inf, sizeof f);
		f[0][0][D]=0;
		For(i, 1, n) For(j, 0, m) For(k, 0, L-1)
		{
			f[i][j][k]=f[i-1][j][k];
			int val=k-d[i]+p[i];
			if(!j || val<0 || val>=L) continue;
			f[i][j][k]=max(f[i][j][k], f[i-1][j-1][val]+d[i]+p[i]);
		}
		int dt=0;
		while(f[n][m][D-dt]<0 && f[n][m][D+dt]<0) dt++;
		if(f[n][m][D-dt]>f[n][m][D+dt]) dt=dt*(-1)+D;
		else dt=dt+D;
		
		int tot=0, sump=0, sumd=0;
		while(m)
		{
			if(f[n][m][dt]!=f[n-1][m][dt])
			{
				ans[++tot]=n;
				dt-=(d[n]-p[n]);
				sump+=p[n], sumd+=d[n];
				m--;
			}
			n--;
		}
		printf("Jury #%d\n", ++T);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", sump, sumd);
		sort(ans+1, ans+tot+1);
		For(i, 1, tot) cout<<' '<<ans[i];
		cout<<endl<<endl;
	}
	return 0;
}
