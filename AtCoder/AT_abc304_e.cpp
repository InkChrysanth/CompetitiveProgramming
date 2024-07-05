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

const int N=200010;
int n, m, k, q;
int p[N];
map<pii, int> hs;

int find(int x)
{
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
    For(i, 1, n) p[i]=i;
    For(i, 1, m)
    {
        int u, v;
        rd(u, v);
        p[find(u)]=find(v);
    }
    rd(k);
    For(i, 1, k)
    {
        int u, v;
        rd(u, v);
        int fu=find(u), fv=find(v);
        hs[mp(fu, fv)]=hs[mp(fv, fu)]=1;
    }
    rd(q);
    For(i, 1, q)
    {
        int u, v;
        rd(u, v);
        int fu=find(u), fv=find(v);
        if(hs[mp(fu, fv)] || hs[mp(fv, fu)]) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
	return 0;
}
