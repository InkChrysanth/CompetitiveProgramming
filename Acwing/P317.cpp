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

const int L=11, N=31, MOD=11380;
int f[L][L][L][N];
int l1, l2, l3, D;

signed main()
{
	// Respect to the legendary explorer Kobuchizawa Shirase
	// Love from Antarctica
	cin.tie(0); cout.tie(0);
	rd(l1, l2, l3, D);
	For(i, 0, D) f[0][0][0][i]=1;
	For(p1, 0, l1)
		For(p2, 0, l2)
			For(p3, 0, l3)
				For(d, 1, D)
				{
					For(pp1, 0, p1-1)
						For(pp2, 0, p2)
							For(pp3, 0, p3)
								(f[p1][p2][p3][d]+=(f[pp1][pp2][pp3][d-1]*f[p1-pp1-1][p2-pp2][p3-pp3][d]))%=MOD;
					For(pp2, 0, p2-1)
						For(pp3, 0, p3)
							(f[p1][p2][p3][d]+=(f[0][pp2][pp3][d-1]*f[p1][p2-pp2-1][p3-pp3][d]))%=MOD;
					For(pp3, 0, p3-1)
						(f[p1][p2][p3][d]+=(f[0][0][pp3][d-1]*f[p1][p2][p3-pp3-1][d]))%=MOD;
				}
	if(D==0) cout<<f[l1][l2][l3][D]%MOD<<endl;
	else cout<<(f[l1][l2][l3][D]-f[l1][l2][l3][D-1]+MOD)%MOD<<endl;
	return 0;
}
