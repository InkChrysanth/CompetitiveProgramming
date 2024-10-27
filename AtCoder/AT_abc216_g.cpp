//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=200010;

struct Fenwick
{
    int cnt[N];
    int lowbit(int x){ return x&-x; }
    void add(int x, int v){ for(; x<N; x+=lowbit(x)) cnt[x]+=v; }
    int query(int x){ int res=0; for(; x; x-=lowbit(x)) res+=cnt[x]; return res; }
    int ask(int l, int r){ return l>r ? 0 : query(r)-query(l-1); }
} tr;

struct Node
{
    int l, r, v;
    Node(int l, int r, int v): l(l), r(r), v(v) {}
    bool operator<(const Node &T)const { return r<T.r; }
};

signed main()
{
	setIO();
	int n, m; cin>>n>>m;
    vector<Node> segs;
    for(int i=1; i<=m; i++)
    {
        int l, r, v; cin>>l>>r>>v;
        segs.eb(l, r, v);
    }
    sort(all(segs));
    vector<bool> ans(n+1);
    each(seg, segs)
    {
        int l=seg.l, r=seg.r, v=seg.v;
        v-=tr.ask(l, r);
        while(v>0)
        {
            int lo=l, hi=r, pos=r;
            while(lo<=hi)
            {
                int mid=(lo+hi)>>1;
                if(tr.ask(mid, hi)==hi-mid+1) hi=mid-1;
                else lo=mid+1, pos=mid; 
            }
            tr.add(pos, 1);
            ans[pos]=1;
            v--;
        }
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
	return 0;
}
// data structures, greedy