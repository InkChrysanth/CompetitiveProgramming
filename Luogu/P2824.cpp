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
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=100010;

int n, m, k;
int a[N];
pair<int, pii> q[N];

struct Node
{
    int l, r, v;
    Node(int l, int r, int v): l(l), r(r), v(v) {}
    Node(int l): l(l) {}
    bool operator<(const Node &T)const { return l<T.l; }
};

set<Node> Chtholly_Tree;

auto split(int pos)
{
    auto it=Chtholly_Tree.lower_bound(Node(pos));
    if(it!=Chtholly_Tree.end() && it->l==pos) return it;
    it--;
    int l=it->l, r=it->r, v=it->v;
    Chtholly_Tree.erase(it);
    Chtholly_Tree.emplace(Node(l, pos-1, v));
    return Chtholly_Tree.emplace(Node(pos, r, v)).fi;
}

void assign(int l, int r, int v)
{
    auto itr=split(r+1), itl=split(l);
    Chtholly_Tree.erase(itl, itr);
    Chtholly_Tree.emplace(Node(l, r, v));
}

int query(int l, int r)
{
    auto itr=split(r+1), itl=split(l);
    int res=0;
    for(; itl!=itr; ++itl)
        if(itl->v==1)
            res+=(itl->r-itl->l+1);
    return res;
}

bool check(int mid)
{
    Chtholly_Tree.clear();
    for(int i=1; i<=n; i++)
        Chtholly_Tree.emplace(Node(i, i, a[i]>=mid));
    Chtholly_Tree.emplace(Node(n+1, n+1, -1));
    for(int i=1; i<=m; i++)
    {
        int opt=q[i].fi, l=q[i].se.fi, r=q[i].se.se, cnt=query(l, r);
        if(!opt) assign(r-cnt+1, r, 1), assign(l, r-cnt, 0);
        else assign(l, l+cnt-1, 1), assign(l+cnt, r, 0);
    }
    return split(k)->v;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>q[i].fi>>q[i].se.fi>>q[i].se.se;
	cin>>k;
    int l=1, r=n, ans=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1, ans=mid;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
