//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
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
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

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
int n, m, k;
bool vis[N];
vector<int> g[N];

signed main()
{
	cin.tie(0); cout.tie(0);
    rd(n, m, k);
    For(i, 1, m)
    {
        int u, v;
        rd(u, v);
        g[u].eb(v);
        g[v].eb(u);
    }
    priority_queue<pii> heap;
    For(i, 1, k)
    {
        int k, h;
        rd(k, h);
        heap.push(mp(h, k));
    }
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        if(vis[t.se]) continue;
        vis[t.se]=1;
        if(t.fi==0) continue;
        for(auto v: g[t.se])
        {
            if(vis[v]) continue;
            heap.push(mp(t.fi-1, v));
        }
    }
    int cnt=0;
    For(i, 1, n) if(vis[i]) cnt++;
    cout<<cnt<<endl;
    For(i, 1, n) if(vis[i]) cout<<i<<' ';
	return 0;
}
/*
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<": "<<(x)<<endl
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
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

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
int n, m, k;
int p[N];
vector<int> g[N];
vector<int> ans;

signed main()
{
	cin.tie(0); cout.tie(0);
    rd(n, m, k);
    For(i, 1, m)
    {
        int u, v;
        rd(u, v);
        g[u].eb(v);
        g[v].eb(u);
    }
    priority_queue<pii> heap;
    For(i, 1, k)
    {
        int k, h;
        rd(k, h);
        heap.push(mp(h, k));
    }
    memset(p, -1, sizeof p);
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        ans.eb(t.se);
        for(auto v: g[t.se])
        {
            if(p[v]<t.fi-1)
            {
                p[v]=t.fi-1;
                heap.push(mp(t.fi-1, v));
            }
        }
    }
    sort(all(ans));
    ans.resize(distance(ans.begin(), unique(all(ans))));
    cout<<ans.size()<<endl;
    for(auto x: ans) cout<<x<<' ';
	return 0;
}
*/