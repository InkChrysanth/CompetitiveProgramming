//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
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
const int N=110;

int n, V;
int m[N], s[N], w[N][N];
double f[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, V);
    For(i, 1, n)
    {
        rd(m[i], s[i]);
        For(j, 1, s[i]) rd(w[i][j]);
    }
    fill(f+1, f+V+1, inf);
    For(k, 1, V)
    {
        For(i, 1, n)
        {
            double res=0;
            int cnt=0;
            For(j, 1, s[i])
            {
                if(w[i][j]!=0)
                {
                    cnt++;
                    res+=f[max(k-w[i][j], 0)];
                }
            }
            // debug(cnt);
            res=res/cnt+1.0*m[i]*s[i]/cnt;
            f[k]=min(f[k], res);
        }
    }
    cout<<fixed<<setprecision(34)<<f[V]<<endl;
	return 0;
}