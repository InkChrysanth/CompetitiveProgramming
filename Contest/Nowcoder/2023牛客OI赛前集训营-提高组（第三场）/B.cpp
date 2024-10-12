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
constexpr int N=1000010;

int rt, tot;
struct SegmentTree
{
    int cnt[N<<2], L[N<<2], R[N<<2];
    ll sum[N<<2];
    void pushup(int u)
    {
        sum[u]=sum[L[u]]+sum[R[u]];
        cnt[u]=cnt[L[u]]+cnt[R[u]];
    }
    void insert(int &u, int l, int r, int pos)
    {
        if(!u){ u=++tot; cnt[u]=sum[u]=L[u]=R[u]=0; }
        if(l==r)
        {
            cnt[u]++; sum[u]+=l;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid) insert(L[u], l, mid, pos);
        else insert(R[u], mid+1, r, pos);
        pushup(u);
    }
    int query(int u, int l, int r, int val)
    {
        if(!u) return 0;
        if(l==r) return min(val/l, cnt[u]);
        int mid=(l+r)>>1;
        if(val<=sum[L[u]]) return query(L[u], l, mid, val);
        else return cnt[L[u]]+query(R[u], mid+1, r, val-sum[L[u]]);
    }
} sgt;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T; cin>>T;
    while(T--)
    {
        rt=tot=0;
        int n, m; cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            int x; cin>>x;
            cout<<(i-1-sgt.query(rt, 1, m, m-x))<<" ";
            sgt.insert(rt, 1, m, x);
        }
        cout<<endl;
    }
	return 0;
}
// data structures(SegmentTree)