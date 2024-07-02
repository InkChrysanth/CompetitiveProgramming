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
#define endl "\n"
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
int n, m;
array<int, N<<1> dist;
array<bool, N<<1> vis;
vector<pii> g[N<<1];

void dijkstra()
{
    fill(all(dist), inf); fill(all(vis), false);
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push(mp(dist[1]=0, 1));
    while(heap.size())
    {
        int u=heap.top().se;
        heap.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(pii t: g[u])
        {
            int v=t.fi, w=t.se;
            if(dist[v]>dist[u]+w)
            {
                heap.push(mp(dist[v]=dist[u]+w, v));
            }
        }
    }
}

signed main()
{
	cin.tie(0); cout.tie(0);
	rd(n, m);
    For(i, 1, n)
    {
        int k;
        rd(k);
        For(j, 1, k)
        {
            int x;
            rd(x);
            g[i+N].eb(mp(x, 1));
            g[x].eb(mp(i+N, 0));
        }
    }    
    dijkstra();
    cout<<((dist[m]==inf)?-1:dist[m]-1)<<endl;
	return 0;
}
