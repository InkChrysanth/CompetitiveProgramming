// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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

const int N=110, M=1<<11;
const int MOD=998244353;

int n;
int a[N];
ll prod=1;
ll f[N][M];

ll qmi(int a, int k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%MOD;
        a=(ll)a*a%MOD;
        k>>=1;
    }
    return res;
}

signed main()
{
	cin.tie(0); cout.tie(0);
    rd(n);
    For(i, 1, n) rd(a[i]), prod=prod*a[i]%MOD;
    f[0][1]=1;
    For(i, 1, n)
    {
        For(k, 0, M-1)
        {
            For(j, 1, min(10, a[i]))
            {
                (f[i][(k|(k<<j))&(M-1)]+=f[i-1][k])%=MOD;
            }
            if(a[i]>10) f[i][k]=(f[i][k]+f[i-1][k]*(a[i]-10))%MOD;
        }
    }
    ll ans=0;
    For(i, 1<<10, M-1) ans=(ans+f[n][i])%MOD;
    ans=ans*qmi(prod, MOD-2)%MOD;
    cout<<ans<<endl;
	return 0;
}
