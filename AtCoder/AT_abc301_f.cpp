// Problem: F - Anti-DDoS
// Contest: AtCoder - Panasonic Programming Contest 2023（AtCoder Beginner Contest 301）
// URL: https://atcoder.jp/contests/abc301/tasks/abc301_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
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
#define pb push_back
#define eb emplace_back
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

using namespace std;

typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf=0x3f3f3f3f;
const ll llinf=0x3f3f3f3f3f3f3f3fll;

int dx[]={0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 0, 1, -1, 1, -1};

template <typename T>
void print(T x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

template <typename T>
void read(T &x)
{
	x=0; char ch=getchar(); T f=1;
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
const int N=300010, MOD=998244353;

int n;
string s;
ll f[N][2];
ll fact[N], infact[N], p26[N];

ll qmi(int a, int k, int p)
{
	ll res=1;
	while(k)
	{
		if(k&1) res=res*a%p;
		a=(ll)a*a%p;
		k>>=1;
	}
	return res;
}

ll C(int n, int k)
{
	return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void init(int n)
{
	fact[0]=1;
	For(i, 1, n) fact[i]=fact[i-1]*i%MOD;
	infact[n]=qmi(fact[n], MOD-2, MOD)%MOD;
	Rep(i, n-1, 0) infact[i]=infact[i+1]*(i+1)%MOD;
	p26[0]=1;
	For(i, 1, n) p26[i]=(p26[i-1]*26)%MOD;
}

int upper(char c)
{
	return c=='?'?26:isupper(c)?1:0;
}
int lower(char c)
{
	return c=='?'?26:islower(c)?1:0;
}

signed main()
{
	cin.tie(0); cout.tie(0);
	cin>>s; n=s.size();
	reverse(all(s));//"SoDD"
	s=" "+s;
	// debug(s);
	init(max(n, 26));
	f[0][0]=1;
	For(i, 1, n)
	{
		f[i][0]=(f[i-1][0]*lower(s[i]))%MOD;//contain ONLY lowercase letters
		f[i][1]=(f[i-1][0]*upper(s[i])+f[i-1][1]*upper(s[i]))%MOD;//a uppercase letter + lowercase letters
	}
	ll ans=(f[n][0]+f[n][1])%MOD;
	unordered_set<char> S;
	int cnt=0;
	// debug(C(3, 2));
	Rep(i, n, 1)
	{
		ll t=0;
		int u=S.size();
		For(k, 0, min(cnt, 26-u))//fill k '?'
			t=(t+C(cnt, k)*p26[cnt-k]%MOD*fact[26-u]%MOD*infact[26-u-k])%MOD;
		ans=(ans+t*lower(s[i])%MOD*f[i-1][1])%MOD;//match "So"
		if(s[i]=='?') cnt++;
		else if(isupper(s[i]))
		{
			if(S.count(s[i]))
				break;
			S.insert(s[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
