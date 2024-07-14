//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define int __int128
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

int n, S, l=1, r=0;
pii a[N];
int f[N], sc[N], st[N];
int q[N];

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, S);
	For(i, 1, n) rd(a[i].fi, a[i].se);
	For(i, 1, n) st[i]=st[i-1]+a[i].fi;
	For(i, 1, n) sc[i]=sc[i-1]+a[i].se;	
	auto k=[&](int p) -> int{ return st[p]+S; };
	auto x=[&](int p) -> int{ return sc[p]; };
	auto y=[&](int p) -> int{ return f[p]; };
	auto find=[&](int l, int r, int s) -> int
	{
		int res=r;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(y(q[mid+1])-y(q[mid])>s*(x(q[mid+1])-x(q[mid])))//find the slope
				r=mid-1, res=mid;
			else
				l=mid+1;
		}
		return q[res];
	};
	q[++r]=0;
	For(i, 1, n)
	{
		int p=find(l, r, k(i));
		f[i]=f[p]+S*(sc[n]-sc[p])+st[i]*(sc[i]-sc[p]);//dp
		//delete the upper point
		while(l<r/*2 points*/ && (y(q[r])-y(q[r-1]))*(x(i)-x(q[r]))>=(y(i)-y(q[r]))*(x(q[r])-x(q[r-1]))) r--;
		q[++r]=i;
	}
	print(f[n]);
	return 0;
}
