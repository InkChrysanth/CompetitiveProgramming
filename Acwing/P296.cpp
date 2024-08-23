//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

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
constexpr int N=10010, M=100010;

int n, st, ed;

struct Node
{
    int l, r, c;
    Node(): l(0), r(0), c(0) {}
    explicit Node(int l, int r, int c): l(l), r(r), c(c){}
    bool operator<(const Node &T)const
    { return (r!=T.r ? r<T.r : l<T.l); }
}a[N];

struct SegmentTree
{
    ll mn[M<<2];
    void pushup(int u)
    { mn[u]=min(mn[u<<1], mn[u<<1|1]); }
    void build(int u, int l, int r)
    {
        if(l==r)
        {
            mn[u]=llinf;
            return;
        }
        int mid=(l+r)>>1;
        build(u<<1, l, mid);
        build(u<<1|1, mid+1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int pos, ll val)
    {
        if(l==r)
        {
            mn[u]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid) modify(u<<1, l, mid, pos, val);
        else modify(u<<1|1, mid+1, r, pos, val);
        pushup(u);
    }
    ll query(int u, int l, int r, int ql, int qr)
    {
        if(ql<=l && qr>=r) return mn[u];
        ll res=llinf;
        int mid=(l+r)>>1;
        if(ql<=mid) cmin(res, query(u<<1, l, mid, ql, qr));
        if(qr>mid) cmin(res, query(u<<1|1, mid+1, r, ql, qr));
        return res;
    }
}sgt;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>st>>ed;
    st++, ed++;
    for(int i=1, l, r, c; i<=n; i++)
    {
        cin>>l>>r>>c;
        a[i]=Node(l+1, r+1, c);
    }
    #define R 1, st-1, ed
    sort(a+1, a+n+1);
    sgt.build(R);
    sgt.modify(R, st-1, 0);
    // for(int i=st-1; i<=ed; i++)
    //     cerr<<sgt.mn[i]<<" \n"[i==ed];
	for(int i=1; i<=n; i++)
        sgt.modify(R, a[i].r, min(sgt.query(R, a[i].r, a[i].r), sgt.query(R, a[i].l-1, a[i].r)+a[i].c));
    ll ans=sgt.query(R, ed, ed);
    #undef R
    cout<<(ans==llinf ? -1 : ans)<<endl;
    return 0;
}
