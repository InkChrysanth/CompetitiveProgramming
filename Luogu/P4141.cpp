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

const int N=2010;

int n, m;
array<int, N> v, f, g;

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
    For(i, 1, n) rd(v[i]);
    f[0]=1;
    For(i, 1, n)
        Rep(j, m, v[i])
            f[j]=(f[j]+f[j-v[i]])%10;
    For(i, 1, n)
    {
        g=f;
        For(j, 1, m)
        {
            if(j>=v[i]) g[j]=(g[j]-g[j-v[i]]+10)%10;
            else g[j]%=10;
            cout<<g[j];
        }
        cout<<endl;
    }
	return 0;
}