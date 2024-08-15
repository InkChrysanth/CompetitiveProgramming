//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define ld long double
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

const int N=5010;
int n;
ld h[N];
ld len[N], cnt[N];

signed main()
{
    cout<<fixed<<setprecision(0);
	rd(n);
	For(i, 1, n) rd(h[i]);
	For(i, 1, n)
	{
		len[i]=1;
		For(j, 1, i-1)
			if(h[j]>h[i]) len[i]=max(len[i], len[j]+1); 
	}
	ld ans1=1;
	For(i, 1, n) ans1=max(ans1, len[i]);
	cout<<ans1<<" ";
	For(i, 1, n)
	{
		if(len[i]==1) cnt[i]=1;
		For(j, 1, i-1)
		{
			if(h[j]>h[i] && len[j]+1==len[i]) cnt[i]+=cnt[j];
			if(h[j]==h[i] && len[j]==len[i]) cnt[i]=0;
		}
	}
	ld ans2=0;
	For(i, 1, n)
		if(len[i]==ans1)
			ans2+=cnt[i];
	cout<<ans2<<endl;
	return 0;
}