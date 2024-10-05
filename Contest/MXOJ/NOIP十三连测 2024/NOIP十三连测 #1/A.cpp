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
int n;
pii p[N], a[N], b[N];

double dis1(int P, int Q)
{
    return abs(p[P].fi-p[Q].fi)+abs(p[P].se-p[Q].se);
}
double dis2(int P, int Q)
{
    return sqrt(1ll*(p[P].fi-p[Q].fi)*(p[P].fi-p[Q].fi)+1ll*(p[P].se-p[Q].se)*(p[P].se-p[Q].se));
}

void solve()
{
    rd(n);
    For(i, 1, n)
    {
        rd(p[i].fi, p[i].se);
        a[i]=mp(p[i].fi+p[i].se, i);
        b[i]=mp(p[i].fi-p[i].se, i);
    }
    sort(a+1, a+n+1, [](pii x, pii y){
        return x.fi<y.fi;
    });
    sort(b+1, b+n+1, [](pii x, pii y){
        return x.fi<y.fi;
    });
    double ans=-114514;
    For(i, 2, n)
    {
        double x=dis1(a[i-1].se, a[i].se)/dis2(a[i-1].se, a[i].se), y=dis1(b[i-1].se, b[i].se)/dis2(b[i-1].se, b[i].se);
        ans=max({ans, x, y});
    }
    cout<<fixed<<setprecision(15)<<ans<<endl;
}

signed main()
{
	cin.tie(0); cout.tie(0);
    Fre("Apair");
    int T;
    rd(T);
    while(T--) solve();
	return 0;
}
