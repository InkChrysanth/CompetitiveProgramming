#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".ans")
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
	x=0; char ch=getchar(); T f=1;
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
const int N=3010;

struct Node
{
    int u, v;
    ll w;
    bool operator<(const Node &T)const
    {
        return w<T.w;
    }
};

int n, q;
pll pts[N];
ll g[N][N], dist[N];
int pre[N];
int p[N];
vector<Node> e;
bool vis[N];

int find(int x)
{
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}

ll get_dist(int i, int j)
{
	ll a=abs(pts[i].fi-pts[j].fi), b=abs(pts[i].se-pts[j].se);
    return a*a*a+b*b*b;
}

ll prim()
{
    fill(dist+1, dist+n+1, llinf);
    dist[1]=0;
    ll res=0;
    For(i, 1, n)
    {
        int t=-1;
        For(j, 1, n)
        {
            if(!vis[j] && (t==-1 || dist[j]<dist[t]))
                t=j;
        }
        vis[t]=1;
        res+=dist[t];
        For(j, 1, n)
        {
            if(dist[j]>g[t][j] && !vis[j])
            {
                dist[j]=g[t][j];
                pre[j]=t;
            }
        }
    }
    return res;
}

signed main()
{
    Fre("logistics");
	cin.tie(0); cout.tie(0);
	rd(n, q);
    For(i, 1, n) rd(pts[i].fi, pts[i].se);
    For(i, 1, n) For(j, 1, n) g[i][j]=get_dist(i, j);
    cout<<prim()<<endl;
    Rep(i, n, 2) e.pb({i, pre[i], g[i][pre[i]]});
    For(i, 1, q)
    {
    	ll ans=0;
        int u, v; ll w;
        rd(u, v, w);
        e.pb({u, v, w});
    	stable_sort(all(e));
    	For(k, 1, n) p[k]=k;
        each(t, e)
        {
            int fu=find(t.u), fv=find(t.v);
            if(fu!=fv)
            {
                p[fv]=fu;
                ans+=t.w;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
