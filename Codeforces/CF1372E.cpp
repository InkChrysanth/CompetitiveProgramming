//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
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
int n, m;
int s[N][N][N];
int f[N][N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
    For(i, 1, n)
    {
        int cnt; rd(cnt);
        For(j, 1, cnt)
        {
            int l, r; rd(l, r);
            For(k, l, r) s[l][r][k]++;
        }
    }
    For(len, 1, m)
    {
        For(l, 1, m-len+1)
        {
            int r=l+len-1;
            For(k, l, r)
            {
                s[l][r][k]+=(s[l+1][r][k]+s[l][r-1][k]-s[l+1][r-1][k]);
                f[l][r]=max(f[l][r], f[l][k-1]+s[l][r][k]*s[l][r][k]+f[k+1][r]);
            }
        }
    }
    cout<<f[1][m]<<endl;
	return 0;
}