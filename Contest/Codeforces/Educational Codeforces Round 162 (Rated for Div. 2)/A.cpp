// Problem: A. Moving Chips
// Contest: Codeforces - Educational Codeforces Round 162 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1923/problem/0
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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

const int N=55;

signed main()
{
	cin.tie(0); cout.tie(0);
	int t; rd(t);
	while(t--)
	{
		int n; rd(n);
		array<int, N> a;
		For(i, 1, n) rd(a[i]);
		int st, ed;
		For(i, 1, n) if(a[i]){st=i;break;}
		Rep(i, n, 1) if(a[i]){ed=i;break;}
		int ans=0;
		For(i, st, ed) if(!a[i]) ans++;
		cout<<ans<<endl;
	}	
	return 0;
}