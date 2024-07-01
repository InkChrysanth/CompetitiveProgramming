//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
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

const int N=300010;
int n, m, ans;
int a[N];
vector<int> g[N];

void dfs(int u)
{
    if(a[u]==-1) return;
    if(a[u]>=1) ans++;
    for(auto v: g[u])
    {
        a[v]=max(a[v], a[u]-1);
        dfs(v);
    }
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
    For(i, 2, n)
    {
        int u; rd(u);
        g[u].eb(i);
    }
    For(i, 1, m)
    {
        int k, d; rd(k, d);
        a[k]=max(a[k], d+1);
    }
    dfs(1);
    cout<<ans<<endl;
	return 0;
}
