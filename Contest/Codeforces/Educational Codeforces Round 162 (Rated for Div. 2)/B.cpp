// Problem: B. Monsters Attack!
// Contest: Codeforces - Educational Codeforces Round 162 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1923/problem/B
// Memory Limit: 256 MB
// Time Limit: 2500 ms

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define int long long
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

const int N=300010;

array<pii, N> mon;

signed main()
{
	cin.tie(0); cout.tie(0);
	int t; rd(t);
	while(t--)
	{
		int n, k; rd(n, k);
		For(i, 1, n) rd(mon[i].se);
		mon[0].fi=0;
		For(i, 1, n)
		{
			int x; rd(x); x=abs(x);
			mon[i].fi=x;
		}
		sort(mon.begin()+1, mon.begin()+n+1);
		For(i, 1, n)
			mon[i].se=mon[i-1].se+mon[i].se;
		bool flag=true;
		For(i, 1, n)
			if(mon[i].se>k*mon[i].fi)
				flag=false;
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}