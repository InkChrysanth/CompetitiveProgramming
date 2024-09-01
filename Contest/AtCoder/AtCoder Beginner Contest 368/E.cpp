//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010, M=2000000000;

int n, m;
int X[N];

struct Node{ int a, b, s, t, id; } a[N];

int lowbit(int x){ return x&-x; }
struct Fenwick
{
    map<int, int> c[N];
    void modify(int k, int pos, int val)
    {
        for(int i=pos; i<=M; i+=lowbit(i))
            cmax(c[k][i], val);
    }
    int query(int k, int pos)
    {
        int res=0;
        for(int i=pos; i; i-=lowbit(i))
            cmax(res, c[k][i]);
        return res;
    }
} tr;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>X[1];
    for(int i=1; i<=m; i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].s>>a[i].t;
        a[i].id=i;
    }
    sort(a+1, a+m+1, [](const auto &x, const auto &y){ return x.s<y.s; });
    for(int i=1; i<=m; i++)
    {
        if(a[i].id!=1) X[a[i].id]=max(0ll, tr.query(a[i].a, a[i].s)-a[i].s);
        tr.modify(a[i].b, a[i].t, a[i].t+X[a[i].id]);
    }
    for(int i=2; i<=m; i++)
        cout<<X[i]<<" ";
	return 0;
}
